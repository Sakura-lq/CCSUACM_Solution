#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MOD = 998244353;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int tot = 1 << n;
    vector<int> dp(tot, 0);

    dp[tot - 1] = 1;

    for (int bit = tot - 1; bit >= 0; bit--)
    {
        dp[bit] %= MOD;
        char pre = '?';

        for (int i = 0; i < n; i++)
        {
            if ((bit >> i) & 1)
            {
                if (pre != s[i])
                {
                    dp[bit ^ (1 << i)] = (dp[bit ^ (1 << i)] + dp[bit]) % MOD;
                }
                pre = s[i];
            }
        }
    }

    cout << dp[0] << endl;
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