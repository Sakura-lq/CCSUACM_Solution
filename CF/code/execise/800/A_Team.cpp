#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;

    while(n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cnt += a + b + c >= 2 ? 1 : 0;
    }

    cout << cnt << endl;
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