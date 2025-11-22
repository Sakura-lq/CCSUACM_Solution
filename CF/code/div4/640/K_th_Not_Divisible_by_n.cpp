#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    int res = 0;

    if (k % (n - 1) == 0)
    {
        cout << k / (n - 1) * n - 1 << endl;
    }
    else
    {
        cout << k / (n - 1) * n + k % (n - 1) << endl;
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