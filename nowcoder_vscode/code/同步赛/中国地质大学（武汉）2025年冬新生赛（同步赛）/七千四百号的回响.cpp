#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int m;
    cin >> m;

    vector<int> d(n + 2, 0);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        d[l - 1]++;
        d[r]--;
    }

    int cnt = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += d[i]; 
        if (cnt % 2 == 1)
        {
            res -= nums[i];
        }
        else
        {
            res += nums[i];
        }
    }

    cout << res << endl;
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