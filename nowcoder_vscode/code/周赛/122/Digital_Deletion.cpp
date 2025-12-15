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
    vector<i64> a(n);

    int cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt0 += a[i] == 0 ? 1 : 0;
    }

    sort(a.begin(), a.end());

    i64 res = 0;
    for (int i = 0; i < n; i++)
    {
        if (res + 1 < a[i])
        {
            cout << n - i << endl;
            return;
        }

        res += a[i];
    }

    cout << cnt0 << endl;
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