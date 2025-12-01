#include <bits/stdc++.h>
using namespace std;
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
vector<pair<int, int>> g[N];

void clear()
{
    for (int i = 0; i < N; i++)
    {
        g[i].clear();
    }
}

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    clear();

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    set<int> st;

    auto dfs1 = [&](auto &&dfs1, int u, int fa, int res) -> void
    {
        if (u == b)
        {
            return;
        }
        st.insert(res);
        for (auto &[v, w] : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            dfs1(dfs1, v, u, res ^ w);
        }
    };

    auto dfs2 = [&](auto &&dfs2, int u, int fa, int res) -> bool
    {
        if (u != b && st.count(res))
        {
            return true;
        }
        for (auto &[v, w] : g[u])
        {
            if (v == fa)
            {
                continue;
            }
            if (dfs2(dfs2, v, u, w ^ res))
            {
                return true;
            }
        }
        return false;
    };

    dfs1(dfs1, a, -1, 0);
    if (dfs2(dfs2, b, -1, 0))
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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