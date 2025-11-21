#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> nums(m + 1);

    for (int i = 0; i <= m; i++)
    {
        cin >> nums[i];
    }

    auto f = [&](int x) -> int
    {
        int res = 0;
        while (x)
        {
            res += x & 1; 
            x >>= 1;     
        }
        return res;
    };

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (f(nums[i] ^ nums[m]) <= k)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
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