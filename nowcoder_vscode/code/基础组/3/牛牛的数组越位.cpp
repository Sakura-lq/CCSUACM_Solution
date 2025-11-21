#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> a(n * m, 0);
    bool flag2 = false;
    bool flag = false;

    for (int i = 0; i < p; i++)
    {
        int x, y, val;
        cin >> x >> y >> val;

        int index = 1LL * x * m + y;

        if (index < 0 || index >= 1LL * n * m)
        {
            flag = true;
        }
        else
        {
            a[index] = val;
            if (x < 0 || x >= n || y < 0 || y >= m)
            {
                flag2 = true;
            }
        }
    }

    if (flag)
    {
        cout << "Runtime error\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i * m + j] << ' ';
        }
        cout << '\n';
    }

    if (flag2)
    {
        cout << "Undefined Behaviour\n";
    }
    else
    {
        cout << "Accepted\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}