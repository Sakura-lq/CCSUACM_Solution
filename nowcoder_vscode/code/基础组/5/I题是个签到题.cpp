#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> nums(n);

    int x;
    int q = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (i == 8)
        {
            q = x;
        }
        nums[i] = {x, i};
    }

    sort(nums.begin(), nums.end());

    if (m * 0.8 <= q)
    {
        cout << "Yes" << endl;
        return;
    }

    int k = 0;
    int pre = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i].second == 8)
        {
            cout << "Yes" << endl;
            return;
        }
        if (pre >= nums[i].first)
        {
            k++;
            pre = nums[i].first;
        }
        if (k == 4)
        {
            break;
        }
    }

    cout << "No" << endl;
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