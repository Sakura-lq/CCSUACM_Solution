#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int a,b;
    cin >> a >> b;

    int cnt = 0;

    while(a <= b)
    {
        a *= 3;
        b *= 2;
        cnt++;
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