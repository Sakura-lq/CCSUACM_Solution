#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << (i % 2 == 0 ? "I love " : "I hate ");
        cout << (i == n ? "it " : "that ");
    }
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