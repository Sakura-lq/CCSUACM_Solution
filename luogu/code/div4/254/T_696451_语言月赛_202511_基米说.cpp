#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int x1, x2, x3;
    int y1, y2, y3;
    cin >> x1 >> x2 >> x3;
    cin >> y1 >> y2 >> y3;

    cout << (x1 * y1 + x2 * y2 + x3 * y3 == 0 ? "Orthogonal" : "Non-Orthogonal") << endl;
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}