#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int N = 1e5 + 7;
int fa[N], siz[N];
char s[N];
vector<int> e[N];

int find(int x)
{
    if (x != fa[x])
    {
        return fa[x] = find(fa[x]);
    }
    return fa[x];
}

void unionset(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y)
    {
        fa[y] = x;
        siz[x] += siz[y];
        siz[y] = 0;
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        fa[i] = i;
        siz[i] = 1;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        if (s[u] == 'W' && s[v] == 'W')
        {
            unionset(u, v);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'W')
        {
            continue;
        }
        int sum = 0, sump = 0;
        for (int k : e[i])
        {
            if (s[k] == 'W')
            {
                int fak = find(k);
                sum += siz[fak];
                sump += siz[fak] * siz[fak];
            }
        }

        res = res + (sum * sum - sump) / 2 + sum;
    }

    cout << res << endl;
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