#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, q;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    cin >> q;

    int a = 0;
    vector<int> L(n + 1, 0);

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v;
            cin >> v;
            a = L[v];
            for (int i = 1; i <= v; i++)
            {
                L[i] = a;
            }
        }
        else if (t == 2)
        {
            int v;
            cin >> v;
            int r = L[v] + w[v];
            a = r;
            for (int i = 1; i <= v; i++)
            {
                L[i] = a - w[i];
            }
        }
        else
        {
            int x;
            cin >> x;
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                int s = L[i];
                int e = s + w[i];
                if (s <= x && e >= x + 1)
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
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