#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums[x]++;
    }

    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        if (nums[i] == 0)
        {
            cnt++;
        }
    }

    cout << max(cnt, nums[k]) << endl;

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
