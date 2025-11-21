#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    int cur_time = 0;
    int cur_side = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        int t, y;
        cin >> t >> y;
        int d = t - cur_time;
        int need = cur_side ^ y;

        if (d % 2 == need)
        {
            ans += d;
        }
        else
        {
            ans += d - 1;
        }

        cur_time = t;
        cur_side = y;
    }

    ans += (m - cur_time);

    cout << ans << endl;
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
