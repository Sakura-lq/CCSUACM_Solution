#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int t[N];
vector<int> g[N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }

    for (int i = 0; i < n / 2; i++)
    {
        t[i] = min(t[i], t[i * 2 + 1] + t[i * 2]);
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        if ((x & y) == y)
        {
            cout << -1 << endl;
        }
        else
        {
            int res = 0;
            while (x != y)
            {
                if (x & 1)
                {
                    res += t[x - 1];
                }
                else
                {
                    res += t[x + 1];
                }
                x >>= 1;
            }

            cout << res << endl;
        }
    }
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