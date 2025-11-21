#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    int res1 = (n - 2) * n % mod * (m - 1) % mod;
    int res2 = (n - 1) * n % mod * (m - 2) % mod;
    int res3 = (m - 2) * m % mod * (n - 1) % mod;
    int res4 = (m - 1) * m % mod * (n - 2) % mod;
    int res5 = (n - 2) % mod * (m - 1) * 2 % mod;
    int res6 = (m - 2) % mod * (n - 1) * 2 % mod;

    int ans = ((res1 + res2 + res3 + res4 - res5 - res6) % mod + mod) % mod;

    cout << (ans * 2) % mod << endl;
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