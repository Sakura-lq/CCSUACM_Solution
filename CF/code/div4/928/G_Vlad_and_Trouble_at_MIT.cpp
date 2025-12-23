#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 INF = 1e18;
const int N = 1e5 + 69;
i64 dp[N][3];
vector<i64> g[N];

void solve()
{
    int n;
    string s;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
    }
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        g[x].push_back(i);
    }

    cin >> s;
    s = "0" + s;

    vector<bool> vis(n + 1, false);
    auto dfs = [&](auto &&dfs, int u) -> void
    {
        dp[u][0] = INF;
        if (s[u] != 'S')
        {
            dp[u][1] = 0;
        }
        else
        {
            dp[u][1] = INF;
        }

        if (s[u] != 'P')
        {
            dp[u][2] = 0;
        }
        else
        {
            dp[u][2] = INF;
        }
        
        i64 res = 0;

        for (int v : g[u])
        {
            dfs(dfs, v);
            dp[u][1] = dp[u][1] + min({dp[v][1], dp[v][2] + 1, dp[v][0]});
            dp[u][2] = dp[u][2] + min({dp[v][2], dp[v][1] + 1, dp[v][0]});
            res += dp[v][0];
        }

        if (s[u] != 'C')
        {
            res = INF;
        }

        dp[u][0] = min({res, dp[u][1] + 1, dp[u][2] + 1});
    };

    dfs(dfs, 1);

    cout << min({dp[1][0], dp[1][1], dp[1][2]}) << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}