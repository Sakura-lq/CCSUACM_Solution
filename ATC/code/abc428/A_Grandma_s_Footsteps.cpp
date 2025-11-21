#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int s, a, b, x;
    cin >> s >> a >> b >> x;

    int k = x / (a + b);
    int yu = x % (a + b);

    cout << s * (k * a + min(yu, a)) << endl;
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