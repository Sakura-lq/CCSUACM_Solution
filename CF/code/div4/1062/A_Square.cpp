#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a == b && b == c && c == d)
    {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}