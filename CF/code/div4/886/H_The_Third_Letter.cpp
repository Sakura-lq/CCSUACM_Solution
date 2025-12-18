#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

int fa[N];
i64 dis[N];

int find(int x)
{
    if (fa[x] != x)
    {
        int root = find(fa[x]);
        dis[x] += dis[fa[x]];
        fa[x] = root;
    }
    return fa[x];
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        dis[i] = 0;
    }

    bool flag = true;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        i64 d;
        cin >> x >> y >> d;

        int fx = find(x), fy = find(y);
        if (fx != fy)
        {
            fa[fx] = fy;
            dis[fx] = dis[y] - dis[x] - d;
        }
        else
        {
            if (dis[y] - dis[x] != d)
            {
                flag = false;
            }
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}