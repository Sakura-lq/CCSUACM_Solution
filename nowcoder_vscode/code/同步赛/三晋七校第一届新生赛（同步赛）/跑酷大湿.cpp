#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> g(n + 1);
    vector<int> f(n + 1, LLONG_MAX), t(n + 1, LLONG_MAX);
    queue<int> q;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        f[x] = 0;
        q.push(x);
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (m != 0)
    {
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : g[u])
            {
                if (f[v] > f[u] + 1)
                {
                    f[v] = f[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    queue<int> qs;
    if (f[s] == 0)
    {
        cout << -1 << endl;
        return;
    }
    t[s] = 0;
    qs.push(s);

    int ans = LLONG_MAX;
    while (!qs.empty())
    {
        int u = qs.front();
        qs.pop();
        if (g[u].size() == 1 && t[u] < f[u])
        {
            ans = min(ans, t[u]);
        }
        for (auto v : g[u])
        {
            if (t[v] > t[u] + 1 && t[u] + 1 < f[v])
            {
                t[v] = t[u] + 1;
                qs.push(v);
            }
        }
    }

    if (ans == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
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