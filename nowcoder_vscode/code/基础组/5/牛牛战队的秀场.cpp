#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
const double PI = acos(-1.0);

void solve()
{
    int n, r;
    cin >> n >> r;
    int i, j;
    cin >> i >> j;

    int c = abs(j - i);
    int k = min(c, n - c);

    cout << fixed << setprecision(6) << 2 * r * sin((k * PI) / n) << endl;
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