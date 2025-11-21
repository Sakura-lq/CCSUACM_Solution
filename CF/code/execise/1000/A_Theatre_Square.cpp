#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m, a;
    cin >> n >> m >> a;

    int x = n / a;
    int y = m / a;
    if (n % a != 0)
    {
        x++;
    }
    if (m % a != 0)
    {
        y++;
    }

    cout << x * y << endl;
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