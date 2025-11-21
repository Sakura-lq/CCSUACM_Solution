#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int a;

    int ans = 0;
    int cnt[105] = {};
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] >> a;
        cnt[a]++;
    }

    for (auto x : nums)
    {
        ans += cnt[x];
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