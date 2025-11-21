#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e6 + 3;
const int N = 3e5 + 7;

vector<int> fact(mod);

int inv(int a)
{
    return a <= 1 ? a : mod - mod / a * inv(mod % a) % mod;
}

void solve()
{
    int n, x, ans = 1;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int k = __lg(b[0] / a[0]);
    for (int i = 1; i < n; i++)
    {
        k = min(k, __lg(b[i] / a[i]));
    }
    x = k;
    vector<int> cnt(k), c(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cnt[j] += b[i] & 1;
            b[i] >>= 1;
        }
        c[i] = b[i] - a[i];
    }
    for (int j = 0; j < k; j++)
    {
        x += cnt[j];
        ans = ans * fact[cnt[j]] % mod;
    }
    int res = accumulate(c.begin(), c.end(), 0LL);
    ans = (res < mod ? ans * fact[res] % mod : 0);
    for (int i : c)
    {
        x += i;
        ans = ans * inv(fact[i]) % mod;
    }
    cout << x << ' ' << ans << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0] = 1;
    for (int i = 1; i < mod; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}