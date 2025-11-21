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

    int mx = 1;
    int cur = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] >= nums[i - 1])
        {
            cur++;
        }
        else
        {
            mx = max(mx, cur);
            cur = 1;
        }
    }
    mx = max(mx, cur);

    cout << mx << endl;
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