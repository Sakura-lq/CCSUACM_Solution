#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int N = 1e6 + 5;
int n, a[N], vis[1 << 18], num[1 << 18];

void solve(int pos)
{
    int S = (1 << (a[pos] - 1));
    vis[S] = 1;
    while (pos < n && !(S & (1 << (a[pos + 1] - 1))))
    {
        ++pos;
        S |= (1 << (a[pos] - 1));
        vis[S] = 1;
    }
}

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i)
    {
        solve(i);
    }

    int flag = (1 << 18) - 1;

    for (int i = 1; i <= flag; ++i)
    {
        num[i] = num[i >> 1] + (i & 1);
    }

    vis[0] = 1;

    vector<int> best(1 << 18, 0);
    for (int mask = 0; mask <= flag; ++mask)
    {
        if (vis[mask])
        {
            best[mask] = num[mask];
        }
    }

    for (int i = 0; i < 18; ++i)
    {
        for (int mask = 0; mask <= flag; ++mask)
        {
            if (mask & (1 << i))
            {
                best[mask] = max(best[mask], best[mask ^ (1 << i)]);
            }
        }
    }

    int ans = 0;

    for (int s = 0; s <= flag; ++s)
    {
        if (!vis[s])
        {
            continue;
        }
        int comp = flag ^ s; 
        ans = max(ans, num[s] + best[comp]);
    }

    cout << ans << endl;
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
