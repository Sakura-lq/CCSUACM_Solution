#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int modpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1LL * res * a % MOD;
        a = 1LL * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int maxv = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxv = max(maxv, a[i]);
    }

    vector<int> cnt(maxv + 2, 0);
    for (int x : a)
        cnt[x]++;

    vector<int> tot(maxv + 2, 0);
    for (int g = 1; g <= maxv; g++)
        for (int k = g; k <= maxv; k += g)
            tot[g] += cnt[k];

    vector<int> f(maxv + 2, 0);
    for (int g = maxv; g >= 1; g--)
    {
        if (tot[g] - cnt[g] > 0)
        {
            f[g] = (modpow(2, tot[g] - cnt[g]) - 1 + MOD) % MOD;
        }
        else
        {
            f[g] = 0;
        }
        for (int k = 2 * g; k <= maxv; k += g)
            f[g] = (f[g] - f[k] + MOD) % MOD;
    }

    int ans = 0;
    for (int g = 1; g <= maxv; g++)
        ans = (ans + f[g]) % MOD;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
