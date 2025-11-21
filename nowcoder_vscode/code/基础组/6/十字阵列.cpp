#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> rows(n + 2, 0);
    vector<int> cols(m + 2, 0);
    vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));

    while (h--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        rows[x] = (rows[x] + z) % mod;
        cols[y] = (cols[y] + z) % mod;
        diff[x][y] = (diff[x][y] - z) % mod;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            diff[i][j] = (diff[i][j] + diff[i][j - 1]) % mod;
        }
    }
    for (int j = 1; j <= m; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            diff[i][j] = (diff[i][j] + diff[i - 1][j]) % mod;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int w = ((rows[i] + cols[j] + diff[i][j]) % mod + mod) % mod;
            res = (res + w * (i + j) % mod) % mod;
        }
    }

    cout << (res + mod) % mod << endl;
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