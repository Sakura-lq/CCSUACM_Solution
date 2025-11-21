#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, x;
    cin >> n;
    
    cin >> x;

    int res = x & 1;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        if(x & 1)
        {
            if(res == 0)
            {
                res = 1;
                ans++;
            }
        }
        else
        {
            if(res == 1)
            {
                res = 0;
                ans++;
            }
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}