#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    if ((l1 < l2 && r1 > r2) || (l2 < l1 && r2 > r1))
    {
        cout << "A" << endl;
    }
    else if (r1 < l2 || r2 < l1)
    {
        cout << "B" << endl;
    }
    else
    {
        cout << "C" << endl;
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