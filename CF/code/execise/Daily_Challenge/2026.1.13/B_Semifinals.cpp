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

    vector<int> a(n), b(n);
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        (a[cnt1] < b[cnt2] ? cnt1 : cnt2)++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << (i < max(cnt1, n / 2) ? 1 : 0);
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << (i < max(cnt2, n / 2) ? 1 : 0);
    }

    cout << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}