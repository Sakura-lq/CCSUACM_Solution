#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> cur(n, vector<int>(m));

    if (m % k != 0)
    {
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cur[i][j] = (p % k) + 1;
                p++;
            }
        }
    }
    else if (n % k != 0)
    {
        int p = 0;
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                cur[i][j] = (p % k) + 1;
                p++;
            }
        }
    }
    else
    {
        for (int c = 0; c < m; c += k)
        {
            for (int r = 0; r < n; r++)
            {
                for (int t = 0; t < k; t++)
                {
                    cur[r][c + t] = (r + t) % k + 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << cur[i][j] << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
