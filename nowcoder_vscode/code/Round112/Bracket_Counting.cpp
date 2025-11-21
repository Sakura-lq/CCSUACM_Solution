#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

struct Bracket
{
    int total;
    int minPref;
};

int n;
vector<Bracket> q;

void solve()
{
    cin >> n;
    vector<string> strs(n);
    q.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
        int balance = 0, minPref = 0;
        for (char c : strs[i])
        {
            if (c == '(')
                balance++;
            else
                balance--;
            minPref = min(minPref, balance);
        }
        q[i] = {balance, minPref};
    }

    vector<unordered_map<int, int>> dp(1 << n);
    dp[0][0] = 1;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (auto &[bal_prev, ways] : dp[mask])
        {
            for (int i = 0; i < n; i++)
            {
                if (!(mask & (1 << i)))
                {
                    int newBal = bal_prev + q[i].total;
                    if (bal_prev + q[i].minPref >= 0)
                    {
                        dp[mask | (1 << i)][newBal] = (dp[mask | (1 << i)][newBal] + ways) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][0] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
}
