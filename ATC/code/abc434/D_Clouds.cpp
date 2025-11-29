#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    vector<vector<int>> a(2025, vector<int>(2025, 0));
    vector<vector<int>> b(2025, vector<int>(2025, 0));

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        d++;
        r++;
        a[u][l]++;
        a[u][r]--;
        a[d][l]--;
        a[d][r]++;
        b[u][l] += i;
        b[u][r] -= i;
        b[d][l] -= i;
        b[d][r] += i;
    }

    for (int i = 0; i < 2025; i++)
    {
        for (int j = 0; j < 2025; j++)
        {
            if (j)
            {
                a[i][j] += a[i][j - 1];
                b[i][j] += b[i][j - 1];
            }
        }
    }

    for (int i = 0; i < 2025; i++)
    {
        for (int j = 0; j < 2025; j++)
        {
            if (i)
            {
                a[i][j] += a[i - 1][j];
                b[i][j] += b[i - 1][j];
            }
        }
    }

    vector<int> c(n + 1, 0);
    for (int i = 1; i <= 2000; i++)
    {
        for (int j = 1; j <= 2000; j++)
        {
            if (a[i][j] == 0)
            {
                c[0]++;
            }
            else if (a[i][j] == 1)
            {
                c[b[i][j]]++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << c[0] + c[i] << endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}