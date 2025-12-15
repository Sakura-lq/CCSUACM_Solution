#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, m;
    cin >> n >> m;

    if (n <= 2 || m <= 2)
    {
        cout << 1 << endl;
        return;
    }

    n = (n + 1) / 2;
    m = (m + 1) / 2;

    cout << (n * m + 1) / 2 << endl;

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