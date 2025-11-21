#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int n;
int t[200005];

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= n)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int query(int k)
{
    int res = 0;
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

    vector<pair<int, int>> date(m);
    vector<int> right(m);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        date[i] = {l, r};
        right[i] = r;
    }

    sort(right.begin(), right.end());
    right.erase(unique(right.begin(), right.end()), right.end());

    sort(date.begin(), date.end(), [&](const pair<int, int> &a, const pair<int, int> &b){
        if(a.first != b.first)
        {
            return a.first < b.first;
        }

        return a.second > b.second;
    });

    auto getr = [&](int r) -> int
    {
        return lower_bound(right.begin(), right.end(), r) - right.begin() + 1;
    };

    n = right.size();

    int ans = 0;

    fill(t, t + 200005, 0);

    for(auto &[l, r] : date)
    {
        int idx = getr(r);

        ans += query(n) - query(idx - 1);

        update(idx, 1);
    }

    cout << ans << endl;
    return;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}