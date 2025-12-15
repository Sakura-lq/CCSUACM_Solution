#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1), pref(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == a[i - 1])
        {
            pref[i] = pref[i - 1];
        }
        else
        {
            pref[i] = i - 1;
        }
    }

    i64 res = 0;

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (i - a[i] + 1 > pref[i])
        {
            dp[i] += dp[i - a[i]] + 1;
        }

        res += dp[i];
    }

    cout << res << endl;
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