#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    int m = 0;
    int ans = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        m -= a;
        m = max(m, 0LL);
        m += b;
        ans = max(m, ans);
    }

    cout << ans << endl;
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