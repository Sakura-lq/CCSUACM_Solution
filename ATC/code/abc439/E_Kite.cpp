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
    vector<pair<int, int>> nums(n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        nums[i] = {x, y};
    }

    sort(nums.begin(), nums.end(), [](auto &&a, auto &&b){ 
        return a.first != b.first ? a.first < b.first : a.second > b.second; 
    });

    vector<int> dp;

    for (auto &[a, b] : nums)
    {
        auto it = lower_bound(dp.begin(), dp.end(), b);
        if (it == dp.end())
        {
            dp.push_back(b);
        }
        else
        {
            *it = b;
        }
    }

    cout << dp.size() << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}