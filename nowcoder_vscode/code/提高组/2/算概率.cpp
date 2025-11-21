#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i)
    {
        int pi = p[i - 1];

        for (int j = 0; j <= i; ++j)
        {
            if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] * ((1 - pi + mod) % mod) % mod;
            }
            else if (j == i)
            {
                dp[i][j] = dp[i - 1][j - 1] * pi % mod;
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] * pi % mod + dp[i - 1][j] * ((1 - pi + mod) % mod) % mod) % mod;
            }
        }
    }

    for (int j = 0; j <= n; ++j)
    {
        cout << dp[n][j] << " ";
    }
    cout << endl;
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