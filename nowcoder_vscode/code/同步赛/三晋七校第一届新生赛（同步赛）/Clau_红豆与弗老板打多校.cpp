#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    double q = 1;
    for (int i = 0; i < n; i++)
    {
        int L, R;
        cin >> L >> R;
        q *= (R - L + 1);
        if (q > 1e9)
        {
            break;
        }
    }
    if (q <= 1e5)
    {
        cout << "NO TLE" << endl;
    }
    else if (q > 1e7)
    {
        cout << "TLE" << endl;
    }
    else
    {
        cout << "POSSIBLE" << endl;
    }

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