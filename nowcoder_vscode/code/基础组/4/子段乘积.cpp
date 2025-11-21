#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int MOD = 998244353;
const int N = 3e5 + 7;

int modpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (__int128)res * a % MOD;
        }
        a = (__int128)a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> inv(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            inv[i] = modpow(a[i], MOD - 2);
        }
    }

    int cnt0 = 0;
    int cur = 1, ans = 0;

    for (int i = 0; i < k; i++)
    {
        if (a[i] == 0)
        {
            cnt0++;
        }
        else
        {
            cur = (__int128)cur * a[i] % MOD;
        }
    }
    if (cnt0 == 0)
    {
        ans = cur;
    }

    for (int i = k; i < n; i++)
    {
        int idx = i - k;
        if (a[idx] == 0)
        {
            cnt0--;
        }
        else
        {
            cur = (__int128)cur * inv[idx] % MOD;
        }
        if (a[i] == 0)
        {
            cnt0++;
        }
        else
        {
            cur = (__int128)cur * a[i] % MOD;
        }

        int val = (cnt0 > 0 ? 0 : cur);
        ans = max(ans, val);
    }

    cout << ans << endl;
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
