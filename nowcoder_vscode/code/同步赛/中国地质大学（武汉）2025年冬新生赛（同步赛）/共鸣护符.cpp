#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int L, R;
    cin >> L >> R;
    int n = R - L + 1;
    if (n == 1)
    {
        cout << "YES" << endl << L << endl;
    }
    else if (n == 2)
    {
        cout << "YES" << endl << R << ' ' << L << endl;
    }
    else if (n == 3)
    {
        if (L % 2 == 1)
        {
            cout << "YES" << endl << R << ' ' << (R - 1) << ' ' << (R - 2) << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}