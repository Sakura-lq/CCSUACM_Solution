#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    int x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    cout << ((x2 / r) - (x1 / r) + 1) * ((y2 / c) - (y1 / c) + 1) << endl;
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