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

    map<int, int> freq;
    int ans = 0;
    int left = 0, right = 0;

    // 维护窗口 [left, right)
    for (int i = 0; i < n; i++)
    {
        while (right < n && freq.size() < k)
        {
            freq[nums[right]]++;
            right++;
        }

        if (freq.size() == k)
        {
            // 右端扩展到最多 k 个不同数
            int tmp_right = right;
            while (tmp_right < n && freq.count(nums[tmp_right]))
            {
                freq[nums[tmp_right]]++;
                tmp_right++;
            }

            int len_min = max(l, (int)tmp_right - i - (tmp_right - right));
            int len_max = min(r, tmp_right - i);

            if (len_min <= len_max)
                ans += len_max - len_min + 1;

            // 收缩左边
            freq[nums[i]]--;
            if (freq[nums[i]] == 0)
                freq.erase(nums[i]);
        }
        else
        {
            freq[nums[i]]--;
            if (freq[nums[i]] == 0)
            {
                freq.erase(nums[i]);
            }
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
        solve();

    return 0;
}
