#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int g[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;

    fill(&g[0][0], &g[0][0] + N * N, INT_MAX);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        g[u][v] = min(g[u][v], w);
        g[v][u] = min(g[v][u], w);
    }

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        for (int j = 1; j <= n; j++)
        {
            
        }
    }
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