#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int cnt2 = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        cnt2++;
    }

    int cnt3 = 0;
    while (n % 3 == 0)
    {
        n /= 3;
        cnt3++;
    }

    if (cnt2 > cnt3)
    {
        cout << -1 << endl;
        return;
    }

    cout << (n == 1 ? 2 * cnt3 - cnt2 : -1) << endl;
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