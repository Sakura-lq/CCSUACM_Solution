#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int N = 3e5 + 7;

int binpow(int a, int b, int p)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    auto fun = [&](int a, int b, int c, int d, int e, int f, int g, int mod) -> bool
    {
        int sum = 0;
        int f1 = 1, f2 = 1, f3 = 1;
        if (a < 0)
        {
            a = abs(a);
            f1 = -1;
        }
        if (b < 0)
        {
            b = abs(b);
            f2 = -1;
        }
        if (c < 0)
        {
            c = abs(c);
            f3 = -1;
        }

        sum = (sum + f1 * binpow(a, d, mod) + mod) % mod;
        sum = (sum + f2 * binpow(b, e, mod) + mod) % mod;
        sum = (sum + f3 * binpow(c, f, mod) + mod) % mod;
        g = (g + mod) % mod;
        return sum == g;
    };

    bool ans = true;
    ans = ans & fun(a, b, c, d, e, f, g, 1e9 + 7);
    ans = ans & fun(a, b, c, d, e, f, g, 1e9 + 6);

    cout << (ans ? "Yes" : "No") << endl;

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