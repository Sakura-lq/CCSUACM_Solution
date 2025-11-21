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
    int yu = 2 * sqrtl(n);

    int ans = 0;
    for (int i = 1; i <= sqrt(n); ++i)
    {
        int k = i * i;
        for (int j = 1; j <= sqrt(k); ++j)
        {
            if (j == i)
            {
                ans += 1;
            }
            else if (k % j == 0)
            {
                ans += 2;
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