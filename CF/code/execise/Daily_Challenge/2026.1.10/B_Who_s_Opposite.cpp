#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 a, b, c;
    cin >> a >> b >> c;

    i64 n = 2 * abs(a - b);
    if (a > n || b > n || c > n)
    {
        cout << -1 << '\n';
    }
    else
    {
        i64 d = n / 2 + c;
        while (d > n)
        {
            d -= n;
        }
        cout << d << '\n';
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}