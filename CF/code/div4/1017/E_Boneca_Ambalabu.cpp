#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> bit(30, 0);

    for (int x : nums)
    {
        for (int b = 0; b < 30; b++)
        {
            if (x >> b & 1)
            {
                bit[b]++;
            }
        }
    }

    int ans = 0;
    for (int x : nums)
    {
        int sum = 0;
        for (int b = 0; b < 30; b++)
        {
            if (x >> b & 1)
            {
                sum += (n - bit[b]) * (1LL << b);
            }
            else
            {
                sum += bit[b] * (1LL << b);
            }
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
