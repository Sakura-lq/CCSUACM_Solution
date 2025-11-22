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

    if (n >= k && (n % 2) == (k % 2))
    {
        cout << "YES\n";
        for (int i = 0; i < k - 1; ++i)
        {
            cout << 1 << ' ';
        }
        cout << (n - (k - 1)) << '\n';
        return;
    }

    if (n >= 2 * k && n % 2 == 0)
    {
        cout << "YES\n";
        for (int i = 0; i < k - 1; ++i)
        {
            cout << 2 << ' ';
        }
        cout << (n - 2 * (k - 1)) << '\n';
        return;
    }

    cout << "NO\n";
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