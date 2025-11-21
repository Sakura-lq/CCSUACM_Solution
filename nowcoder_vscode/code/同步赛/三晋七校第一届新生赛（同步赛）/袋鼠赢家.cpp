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
    int A, B;
    cin >> n >> A >> B;
    int q = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ans += min(A * (x - q), B);
        q = x;
    }
    cout << ans << endl;
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