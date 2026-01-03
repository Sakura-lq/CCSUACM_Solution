#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    i64 n, k, q;
    cin >> n >> k >> q;

    vector<i64> d(k);
    vector<i64> t(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> d[i];
    }
    for (int i = 0; i < k; ++i)
    {
        cin >> t[i];
    }

    while (q--)
    {
        i64 x;
        cin >> x;

        if (x == 0)
        {
            cout << 0 << " ";
            continue;
        }

        int idx = upper_bound(d.begin(), d.end(), x) - d.begin() - 1;

        i64 nxt = (idx == -1) ? 0 : d[idx];
        i64 res = (idx == -1) ? 0 : t[idx];

        if (idx == k - 1)
        {
            cout << res << " ";
            continue;
        }

        res += ((x - nxt) * (t[idx + 1] - res)) / (d[idx + 1] - nxt);

        cout << res << " ";
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}