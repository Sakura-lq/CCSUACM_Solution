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

    vector<int> a(n);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        res += a[i];
    }

    int ping = res / n;

    int ans = 0;
    for (int x : a)
    {
        ans += x - ping;
    }

    cout << (ans == 0 ? "Yes" : "No") << endl;

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