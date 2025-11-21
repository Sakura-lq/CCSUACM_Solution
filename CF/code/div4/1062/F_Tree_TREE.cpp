#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int n, k, res;
int sum[N];
vector<int> e[N];
void dfs(int u, int fa)
{
    sum[u] = 1;
    for (int v : e[u])
    {
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
        sum[u] += sum[v];
    }
}
void DFS(int u, int fa)
{
    if (sum[u] >= k)
    {
        res = res + n - sum[u];
    }
    if (n >= k)
    {
        res = res + 1;
    }
    for (int v : e[u])
    {
        if (v == fa)
        {
            continue;
        }
        if (n - sum[v] >= k)
        {
            res = res + sum[v];
        }
        DFS(v, u);
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        sum[i] = 0;
        e[i].clear();
    }
    n = k = res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    DFS(1, 0);
    cout << res << endl;
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