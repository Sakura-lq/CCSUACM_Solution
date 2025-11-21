#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> nums(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int ans = 1e9;

    for (int i = n; i <= m; i++)
    {
        ans = min(ans, nums[i - 1] - nums[i - n]);
    }

    cout << ans << endl;
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