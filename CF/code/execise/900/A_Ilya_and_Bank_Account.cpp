#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    if (n >= 0)
    {
        cout << n << endl;
        return;
    }
    else
    {
        int a = n / 10;
        int b = a / 10 * 10 + (n % 10);
        cout << (a > b ? a : b) << endl;
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