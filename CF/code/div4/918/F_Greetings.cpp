#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

i64 n;
i64 t[N];

int lowbit(i64 x)
{
    return x & -x;
}

void update(i64 k, i64 v)
{
    while (k <= n)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

i64 query(i64 k)
{
    i64 res = 0;
    while (k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }

    return res;
}

void solve()
{
    int m;
    cin >> m;

    vector<pair<i64, i64>> date(m);
    vector<i64> right(m);
    for (int i = 0; i < m; i++)
    {
        i64 l, r;
        cin >> l >> r;

        date[i] = {l, r};
        right[i] = r;
    }
    
    sort(right.begin(), right.end());
    right.erase(unique(right.begin(), right.end()), right.end());

    sort(date.begin(), date.end(), [&](const pair<i64, i64> &a, const pair<i64, i64> &b)
    {
        if(a.first != b.first)
        {
            return a.first < b.first;
        }

        return a.second > b.second; 
    });

    auto getr = [&](i64 r) -> int
    {
        return lower_bound(right.begin(), right.end(), r) - right.begin() + 1;
    };

    n = right.size();

    i64 ans = 0;

    fill(t, t + 300005, 0);

    for (auto &[l, r] : date)
    {
        i64 idx = getr(r);

        ans += query(n) - query(idx - 1);

        update(idx, 1);
    }

    cout << ans << endl;
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