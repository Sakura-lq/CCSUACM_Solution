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

    vector<int> s(n), g(n);
    vector<string> a(n), b(n);
    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        string x, y;
        cin >> x >> y;

        v.push_back(x);
        v.push_back(y);
        a[i] = x;
        b[i] = y;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for (int i = 0; i < n; i++)
    {
        s[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        g[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        dp[1 << i][i] = 1;  // 初始状态
    }

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int lst = 0; lst < n; lst++)
        {
            // 如果当前状态不可选
            if (!dp[mask][lst])
            {
                continue;
            }

            // 如果当前状态可选, 查看是否可以扩展
            for (int i = 0; i < n; i++)
            {
                if (mask >> i & 1)
                {
                    continue;
                }

                if (s[lst] == s[i] || g[lst] == g[i])
                {
                    dp[mask | (1 << i)][i] |= dp[mask][lst];
                }
            }
        }
    }

    int res = 0;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            // 如果当前状态可行
            if (dp[mask][i])
            {
                // 找到最大值
                res = max(res, __popcount(mask));
            }
        }
    }

    // 正难则反
    cout << n - res << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}