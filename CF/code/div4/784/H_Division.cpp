#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int x;
    cin >> x;

    if (x <= 1399)
    {
        cout << "Division 4" << endl;
    }
    else if (x <= 1599)
    {
        cout << "Division 3" << endl;
    }
    else if (x <= 1899)
    {
        cout << "Division 2" << endl;
    }
    else
    {
        cout << "Division 1" << endl;
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