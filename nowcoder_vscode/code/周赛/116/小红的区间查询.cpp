#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<tuple<int, int, int>> qu(n);
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        qu[i] = {l, r, i + 1};
    }

    sort(qu.begin(), qu.end(), [](const auto &a, const auto &b)
         { return get<0>(a) < get<0>(b); });

    vector<int> lefts(n);
    for (int i = 0; i < n; ++i)
    {
        lefts[i] = get<0>(qu[i]);
    }

    while (q--)
    {
        int x;
        cin >> x;

        auto it = upper_bound(lefts.begin(), lefts.end(), x);
        if (it == lefts.begin())
        {
            cout << -1 << '\n';
            continue;
        }

        int idx = it - lefts.begin() - 1;
        int l = get<0>(qu[idx]);
        int r = get<1>(qu[idx]);
        if (x <= r)
        {
            cout << get<2>(qu[idx]) << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
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
