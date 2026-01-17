#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m, l;
    i64 mm, mx;

    cin >> n >> m >> l >> mm >> mx;

    vector<vector<pair<int, i64>>> g(n + 1);
    vector<int> flag(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        i64 c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
    }

    auto dfs = [&](auto &&dfs, int u, int d, i64 v)
    {
        if (v > mx)
        {
            return;
        }
        if (d == l)
        {
            if (mm <= v && v <= mx)
            {
                flag[u] = 1;
            }
            return;
        }
        for (auto &e : g[u])
        {
            dfs(dfs, e.first, d + 1, v + e.second);
        }
    };

    dfs(dfs, 1, 0, 0);

    for (int i = 1; i <= n; i++)
    {
        if (flag[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
