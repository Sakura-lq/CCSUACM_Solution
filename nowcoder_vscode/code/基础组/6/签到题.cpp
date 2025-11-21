#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b <= c || a + c <= b || b + c <= a)
    {
        cout << "wtnl" << endl;
        return ;
    }

    double r1 = (a + b - c) / 2.0;
    double r2 = (a + c - b) / 2.0;
    double r3 = (b + c - a) / 2.0;

    if (r1 <= 0 || r2 <= 0 || r3 <= 0)
    {
        cout << "No" << endl;
        return ;
    }

    vector<double> d = {r1, r2, r3};
    sort(d.begin(), d.end());

    cout << "Yes" << endl;
    printf("%.2f %.2f %.2f\n", d[0], d[1], d[2]);
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