#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
char mi[55][55];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mi[i][j];
        }
    }

    vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

    auto dfs = [&](auto &&dfs, int i, int j) -> int
    {
        if (i >= n || j >= m)
        {
            return 0;
        }
        if (i == n - 1 && j == m - 1)
        {
            return 1;
        }
        if(memo[i][j] != -1)
        {
            return memo[i][j];
        }

        int res = 0;
        if (mi[i][j] == 'D' || mi[i][j] == 'B')
        {
            res += dfs(dfs, i + 1, j);
        }
        if (mi[i][j] == 'R' || mi[i][j] == 'B')
        {
            res += dfs(dfs, i, j + 1);
        }

        memo[i][j] = res % mod;

        return memo[i][j];
    };

    cout << dfs(dfs, 0, 0) << endl;
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