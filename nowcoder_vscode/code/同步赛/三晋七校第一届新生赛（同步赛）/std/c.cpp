#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second
using namespace std;
const int mod = 998244353;

int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (res % mod) * a % mod;
        a %= mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int getsqrt(int n)
{
    n %= mod;
    return (n % mod * (n + 1) % mod) % mod * (2 * n % mod + 1) % mod * qmi(6, mod - 2) % mod;
}

int get(int l, int r)
{
    return (getsqrt(r) % mod - getsqrt(l - 1) % mod + mod) % mod;
}
void solve()
{
    int k;
    cin >> k;

    auto check = [&](int x) -> bool
    {
        __int128 ans = 0;
        for (int i = 1; i <= x / i; i++)
        {
            int L = x / i - i;
            ans += 2LL * L + 1;
            if (ans >= k) return true;
        }
        return ans >= k;
    };

    int l = 0, r = 1e12;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    int ans = 0, cnt = 0;
    int x = r - 1;
    for (int i = 1; i <= x / i; i++)
    {
        int L = x / i - i;
        cnt += 2LL * L + 1;
        int t = i % mod;
        ans = (ans + (__int128)((2LL * t % mod * t % mod * get(i, i + L) % mod - t % mod * t % mod * t % mod * t % mod + mod) % mod)) % mod;
    }
    r %= mod;
    ans = (ans + (__int128)(k - cnt) % mod * (r % mod * r % mod) % mod) % mod;
    cout << ans << endl;
}

signed main()
{
    IOS
    int T = 1;
    //cin >> T;
    while (T--)solve();
    return 0;
}
