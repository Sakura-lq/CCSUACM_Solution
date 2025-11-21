#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    if (n >= 2 * k - 1)
    {
        cout << 2 * k - 1 << endl;
    }
    else
    {
        cout << 2 * (k - n / 2 - (n % 2 == 0 ? 0 : 1)) << endl;
    }

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