#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> dp(n + 1, 1e18);
    dp[0] = 0;

    deque<int> q;

    for (int i = 1; i <= n; ++i)
    {
        if (i >= k)
        {
            int j = i - k;
            int val = dp[j] - a[j];
            while (!q.empty() && (dp[q.back()] - a[q.back()] >= val))
            {
                q.pop_back();
            }
            q.push_back(j);
        }
        if (i >= k)
        {
            dp[i] = a[i - 1] + dp[q.front()] - a[q.front()];
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