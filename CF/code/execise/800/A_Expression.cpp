#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int mx = 0;
    mx = max(mx, a + b + c);
    mx = max(mx, a * b + c);
    mx = max(mx, a + b * c);
    mx = max(mx, a * b * c);
    mx = max(mx, (a + b) * c);
    mx = max(mx, a * (b + c));

    cout << mx << endl;
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