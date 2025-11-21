#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int k, n, w;
    cin >> k >> n >> w;

    if(w == 1)
    {
        cout << (n > k ? 0 : abs(n - k)) << endl;
        return;
    }
    int ans = n - (w * k + w * (w - 1) * k / 2);

    cout << (ans > 0 ? 0 : abs(ans)) << endl;
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