#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
string A = "nico", B = "niconi", C = "niconiconi";

void solve()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string s;
    cin >> s;
    s = " " + s;
    vector<int> dp(n + 5, 0);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (i >= 4 && s.substr(i - 3, 4) == A)
        {
            dp[i] = max(dp[i], dp[i - 4] + a);
        }
        if (i >= 6 && s.substr(i - 5, 6) == B)
        {
            dp[i] = max(dp[i], dp[i - 6] + b);
        }
        if (i >= 10 && s.substr(i - 9, 10) == C)
        {
            dp[i] = max(dp[i], dp[i - 10] + c);
        }
    }

    cout << dp[n] << endl;
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