#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, k, x;
    cin >> n >> k >> x;

    i64<i64> a(n);
    for (i64 i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    i64<i64> pref(n + 1, 0);
    for (i64 i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + a[i];
    }

    if (pref[k] < x)
    {
        cout << -1 << endl;
        return;
    }

    i64 ans = -1;
    for (i64 i = 1; i <= n; i++)
    {
        if (pref[i] - pref[i - max(0LL, k - (n - i))] >= x)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}