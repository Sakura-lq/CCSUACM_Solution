#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    if (k == 0)
    {
        cout << 0 << endl;
        return;
    }

    auto f = [](const vector<int> &nums, int k, int l, int r) -> int
    {
        int n = nums.size();
        unordered_map<int, int> hash;
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++)
        {
            hash[nums[right]]++;
            while (hash.size() > k)
            {
                hash[nums[left]]--;
                if (hash[nums[left]] == 0)
                {
                    hash.erase(nums[left]);
                }
                left++;
            }
            int len = right - left + 1;
            int min_len = max(l, 0LL);
            int max_len = min(r, len);
            if (min_len <= max_len)
            {
                ans += max_len - min_len + 1;
            }
        }
        return ans;
    };

    cout << f(nums, k, l, r) - f(nums, k - 1, l, r) << endl;
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
