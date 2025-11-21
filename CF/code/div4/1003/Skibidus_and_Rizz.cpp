#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    if (abs(n - m) > k)
    {
        cout << -1 << endl;
        return;
    }

    string ans = "";

    while (n > 0 || m > 0)
    {
        if (n > m)
        {
            ans += "0";
            n--;
            if (m > 0)
            {
                ans += "1";
                m--;
            }
        }
        else
        {
            ans += "1";
            m--;
            if (n > 0)
            {
                ans += "0";
                n--;
            }
        }
    }

    cout << ans << endl;
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
