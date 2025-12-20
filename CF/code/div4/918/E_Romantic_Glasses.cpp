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
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    map<i64, i64> hash;
    hash[0] = 1;

    i64 res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (a[i] * (i % 2 ? -1 : 1));

        if (hash.count(res))
        {
            cout << "YES" << endl;
            return;
        }
        hash[res]++;
    }

    cout << "NO" << endl;
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