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
    vector<int> a(n), c(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> c[i];
    }

    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int m = sorted.size();

    vector<int> dp(m, 0), dp2(m, 0);

    for (int j = 0; j < m; ++j)
    {
        if (a[0] == sorted[j])
        {
            dp[j] = 0;
        }
        else
        {
            dp[j] = c[0];
        }
    }

    for (int i = 1; i < n; ++i)
    {
        vector<int> pref(m, 0);
        pref[0] = dp[0];
        for (int j = 1; j < m; ++j)
        {
            pref[j] = min(pref[j - 1], dp[j]);
        }
        for (int j = 0; j < m; ++j)
        {
            int cost = (a[i] == sorted[j]) ? 0 : c[i];
            dp2[j] = pref[j] + cost;
        }
        dp.swap(dp2);
    }

    cout << *min_element(dp.begin(), dp.end()) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
