#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    int base = 1;
    while (n)
    {
        if (k <= (n + 1) / 2)
        {
            cout << (2 * k - 1) * base << endl;
            return;
        }

        k -= (n + 1) / 2;
        n /= 2;
        base *= 2;
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