#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 1e5 + 7;

vector<int> g[205];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        g[i].clear();
    }

    i64 res = n * (n + 1) / 2;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (g[i].size() == 1)
        {
            st.insert(g[i][0]);
        }
    }

    cout << st.size() << " " << g[*st.begin()].size() - 1 << endl;

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

