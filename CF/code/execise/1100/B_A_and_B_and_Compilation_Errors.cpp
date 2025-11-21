#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    int x;
    int sum1 = 0, sum2 = 0, sum3 = 0;

    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        sum1 += x;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        cin >> x;
        sum2 += x;
    }

    for (int i = 0; i < n - 2; ++i)
    {
        cin >> x;
        sum3 += x;
    }

    cout << sum1 - sum2 << endl << sum2 - sum3 << endl;

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