#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    auto check = [&](auto &&check, int n, int m) -> bool
    {
        if (n == m)
        {
            return true;
        }
        else if (n % 3 != 0)
        {
            return false;
        }
        else
        {
            return check(check, n / 3, m) || check(check, n / 3 * 2, m);
        }
    };

    cout << (check(check, n, m) ? "YES" : "NO") << endl;
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