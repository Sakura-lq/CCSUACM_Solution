#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int mod = 1e9 + 7;

void solve()
{
    int n, l, r, a;
    cin >> n >> l >> r >> a;

    int ans = 0;

    int base = 1;
    for(int i = 0; i < a - 1; i++)
    {
        base *= 10;
    }

    if(r < base)
    {
        cout << 0 << endl;
        return ;
    }

    auto f = [&](int x) -> bool
    {
        int k = 0;
        vector<int>nums(11, 0);
        while(x)
        {
            int yu = x % 10;
            if(nums[yu])
            {
                return false;
            }

            nums[yu]++;
            k++;
            x /= 10;
        }

        return k == a ? true : false;
    };

    for(int i = max(l, base); i <= r; i++)
    {
        ans = ans + (f(i) == true ? 1 : 0) % mod;
    }

    cout << ans << endl;
    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}