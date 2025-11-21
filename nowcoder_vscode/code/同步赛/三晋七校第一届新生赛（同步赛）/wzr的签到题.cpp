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
    cin >> n >> x;
    int cnt = 0;
    bool r = false;
    while (x > 0)
    {
        int a = n / 2, b = n - n / 2;
        if (!r && a % 2 == 1 && b % 2 == 1)
        {
            a--, b++;
        }
        x -= a;
        cnt++;
        n -= a;
        r = true;
    }
    cout << cnt << '\n';
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