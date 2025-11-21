#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    int nums[100] = {};
    int pre[100] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + nums[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans = max(ans, (pre[i + j] - pre[i]) / j);
        }
    }

    cout << ans << endl;
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