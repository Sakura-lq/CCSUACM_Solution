#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        if(q > 0 && q < y)
        {
            ans++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        if (q > 0 && q < x)
        {
            ans++;
        }
    }

    cout << ans << endl;

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