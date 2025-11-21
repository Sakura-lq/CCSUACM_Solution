#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

int qpow(int a, int b)
{
    int res = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int fsum(int sz)
{
    int sum = 0;
    for (int i = 0; i < sz; ++i)
    {
        int x;
        scanf("%lld", &x);
        sum = (sum + x % mod) % mod;
    }
    return sum;
}

void solve()
{
    int n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);

    int ans = 0;

    ans = fsum(n) * qpow(n, mod - 2) % mod;
    ans = ans * fsum(m) % mod;
    ans = ans * qpow(m, mod - 2) % mod;
    ans = ans * fsum(k) % mod;
    ans = ans * qpow(k, mod - 2) % mod;

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