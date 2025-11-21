#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;
    while(k--)
    {
        n = (n % 10 == 0 ? n / 10 : n - 1);
    }

    cout << n << endl;
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