#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

unsigned long long dp[61][6];

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < 6; i++)
    {
        dp[1][i] = 0;
    }
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][3] + 1;
        dp[i][2] = dp[i - 1][4] + dp[i - 1][0];
        dp[i][3] = dp[i - 1][5] + dp[i - 1][1];
        dp[i][4] = dp[i - 1][2] + dp[i - 1][5];
        dp[i][5] = dp[i - 1][3] + dp[i - 1][4];
    }

    cout << "A->B:" << dp[n][0] << "\n";
    cout << "A->C:" << dp[n][1] << "\n";
    cout << "B->A:" << dp[n][2] << "\n";
    cout << "B->C:" << dp[n][3] << "\n";
    cout << "C->A:" << dp[n][4] << "\n";
    cout << "C->B:" << dp[n][5] << "\n";

    unsigned long long sum = 0;
    for (int i = 0; i < 6; i++)
    {
        sum += dp[n][i];
    }
    cout << "SUM:" << sum << "\n";
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