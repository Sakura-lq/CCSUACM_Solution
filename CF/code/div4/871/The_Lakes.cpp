#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int dirt[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    auto dfs = [&](auto &&dfs, int i, int j, int &res) -> void
    {
        if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || g[i][j] == 0)
        {
            return;
        }

        res += g[i][j];
        vis[i][j] = -1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dirt[k][0];
            int y = j + dirt[k][1];

            dfs(dfs, x, y, res);
        }

        return;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && g[i][j] != 0)
            {
                int res = 0;
                dfs(dfs, i, j, res);
                mx = max(res, mx);
            }
        }
    }

    cout << mx << endl;
    return;
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