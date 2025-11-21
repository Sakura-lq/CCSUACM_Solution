#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int c, d;
    cin >> c >> d;
    int ans = 0;

    for (int len = 1; len <= 12; len++)
    {
        int t = 1;
        for (int i = 0; i < len; i++)
        {
            t *= 10;
        }

        int mm = max(1LL, t / 10 - c);
        int mx = min(d, t - 1 - c);
        if (mm > mx)
        {
            continue;
        }

        int base = c * t + c;
        int l = sqrtl(base + mm);
        int r = sqrtl(base + mx) + 2;

        for (int k = l; k <= r; k++)
        {
            int x = k * k - base;
            if (x >= mm && x <= mx)
            {
                ans++;
            }
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