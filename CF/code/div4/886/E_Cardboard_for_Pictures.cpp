#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, c;
    cin >> n >> c;

    __int128_t sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        i64 x;
        cin >> x;
        sum1 += x;
        sum2 += (__int128_t)x * x;
    }

    i64 x1 = (-sum1 + sqrtl(sum1 * sum1 - n * (sum2 - c))) / (2 * n);

    cout << x1 << endl;

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