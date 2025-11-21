#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int n;
int t[500005];

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

int getsum(int k)
{
    int res = 0;
    while (k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }

    return res;
}

int query(int k)
{
    return getsum(n) - getsum(k);
}

void solve()
{
    int m;

    cin >> m;
    while (m)
    {
        vector<int> date(m);

        for (int i = 0; i < m; i++)
        {
            cin >> date[i];
        }

        vector<int> sr(date);

        sort(sr.begin(), sr.end());
        sr.erase(unique(sr.begin(), sr.end()), sr.end());

        auto getr = [&](int r) -> int
        {
            return lower_bound(sr.begin(), sr.end(), r) - sr.begin() + 1;
        };

        n = sr.size();

        int ans = 0;

        for (int x : date)
        {
            int idx = getr(x);

            ans += query(idx - 1);

            update(idx, 1);
        }

        cout << ans << endl;
        fill(t, t + 500005, 0);

        cin >> m;
    }

    return;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}