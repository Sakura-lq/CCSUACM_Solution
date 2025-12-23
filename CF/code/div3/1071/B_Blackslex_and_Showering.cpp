#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    i64 res = 0;
    for (int i = 1; i < n; ++i)
    {
        res += abs(a[i] - a[i - 1]);
    }

    i64 mx = max(abs(a[1] - a[0]), abs(a[n - 1] - a[n - 2]));

    for (int k = 1; k < n - 1; ++k)
    {
        i64 diff = abs(a[k] - a[k - 1]) + abs(a[k + 1] - a[k]) - abs(a[k + 1] - a[k - 1]);
        if (diff > mx)
        {
            mx = diff;
        }
    }

    cout << res - mx << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}