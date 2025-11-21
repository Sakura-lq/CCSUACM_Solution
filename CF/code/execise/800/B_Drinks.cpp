#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        sum += p;
    }

    double res = sum * 1.0 / n;

    cout << fixed << setprecision(12) << res << endl;
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
