#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int n, m, s;
int vis[200005], dis[200005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
vector<pair<int, int>> g[200005];

void dijkstra(int x)
{
    for (int i = 1; i <= 2 * n + 1; i++)
    {
        dis[i] = LLONG_MAX;
        vis[i] = 0;
    }

    dis[x] = 0;
    q.push({0, x});

    while(!q.empty())
    {
        auto [d, v] = q.top();
        q.pop();

        if(vis[v])
        {
            continue;
        }

        vis[v] = 1;

        for(auto &[u, w] : g[v])
        {
            if(dis[u] > dis[v] + w)
            {
                dis[u] = dis[v] + w;
                q.push({dis[u], u});
            }
        }
    }
}

void solve()
{
    cin >> n >> m;

    s = 2 * n + 1;

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;

        g[v].emplace_back(u, w);
        g[u].emplace_back(v, w);

        g[v].emplace_back(u + n, 0);
        g[u].emplace_back(v + n, 0);
        g[v].emplace_back(v + n, 0);
        g[u].emplace_back(u + n, 0);

        g[u + n].emplace_back(v + n, w);
        g[v + n].emplace_back(u + n, w);
    }

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        g[s].emplace_back(i, a);
    }

    dijkstra(s);

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dis[i + n]);
    }

    cout << ans << endl;

    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}