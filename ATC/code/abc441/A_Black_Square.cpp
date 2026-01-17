#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int p, q, x, y;
    cin >> p >> q >> x >> y;

    if ((x >= p) && (x <= p + 99) && (y >= q) && (y <= q + 99))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}