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
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        mx = max(nums[i], mx);
    }

    cout << (mx > n ? mx : n) << endl;
    return;
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