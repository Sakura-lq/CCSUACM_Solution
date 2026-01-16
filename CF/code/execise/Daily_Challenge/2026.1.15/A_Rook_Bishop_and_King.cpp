#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int k1 = abs(x1 - x2), k2 = abs(y1 - y2);

    cout << (x1 == x2 || y1 == y2 ? 1 : 2) << " ";
    if ((x1 + y1) % 2 != (x2 + y2) % 2)
    {
        cout << 0 << " ";
    }
    else
    {
        cout << (k1 == k2 ? 1 : 2) << " ";
    }
    cout << (k1 == k2 ? k1 : max(k1, k2)) << endl;
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