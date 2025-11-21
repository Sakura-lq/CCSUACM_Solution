#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    int x = 0, y = 0, z = 0;

    while (n--)
    {
        int dx, dy, dz;
        cin >> dx >> dy >> dz;

        x += dx;
        y += dy;
        z += dz;
    }

    cout << ((x == 0 && y == 0 && z == 0) ? "YES" : "NO") << endl;
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