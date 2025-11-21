#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int d1[400000], d2[400000], a[100005];

void update1(int s, int t, int p)
{
    if (s == t)
    {
        d1[p] = a[s];
        return;
    }

    int m = s + ((t - s) >> 1);

    update1(s, m, p << 1);
    update1(m + 1, t, (p << 1) + 1);

    d1[p] = d1[p << 1] + d1[(p << 1) + 1];
}

int query1(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        return d1[p];
    }

    int m = s + ((t - s) >> 1);

    int res = 0;
    if (l <= m)
    {
        res += query1(l, r, s, m, p << 1);
    }

    if (r > m)
    {
        res += query1(l, r, m + 1, t, (p << 1) + 1);
    }

    return res;
}

void update2(int s, int t, int p)
{
    if (s == t)
    {
        d2[p] = a[s];
        return;
    }

    int m = s + ((t - s) >> 1);

    update2(s, m, p << 1);
    update2(m + 1, t, (p << 1) + 1);

    d2[p] = min(d2[p << 1], d2[(p << 1) + 1]);
}

int query2(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        return d2[p];
    }

    int m = s + ((t - s) >> 1);

    int res = 1e9;
    if (l <= m)
    {
        res = min(res, query2(l, r, s, m, p << 1));
    }

    if (r > m)
    {
        res = min(res, query2(l, r, m + 1, t, (p << 1) + 1));
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    update1(1, n, 1);
    update2(1, n, 1);

    int k = 0;
    double res = -1e18;
    vector<int> ans;
    for (int i = 1; i <= n - 2; i++)
    {
        double x = (query1(i + 1, n, 1, n, 1) - query2(i + 1, n, 1, n, 1)) / ((n - i - 1) * 1.0);
        if (x > res + 1e-12)
        {
            ans.clear();
            ans.push_back(i);
            res = x;
        }
        else if (fabs(x - res) < 1e-12)
        {
            ans.push_back(i);
        }
    }

    for (auto x : ans)
    {
        cout << x << endl;
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