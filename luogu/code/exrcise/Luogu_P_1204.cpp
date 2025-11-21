#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int d[4000005], b[4000005], v[4000005];

void build(int s, int t, int p)
{
    if (s + 1 == t)
    {
        d[p] = 0;
        return;
    }

    int m = (s + t) / 2;

    build(s, m, p << 1);
    build(m, t, (p << 1) + 1);

    d[p] = d[p << 1] + d[(p << 1) + 1];
}

void update(int l, int r, int s, int t, int p, int c)
{
    if (r <= s || l >= t)
    {
        return;
    }

    if (l <= s && t <= r)
    {
        d[p] = (t - s) * c;
        b[p] = c;
        v[p] = 1;
        return;
    }

    int m = (s + t) / 2;

    if (v[p])
    {
        d[p << 1] = b[p] * (m - s);
        d[(p << 1) + 1] = b[p] * (t - m);
        b[p << 1] = b[(p << 1) + 1] = b[p];
        v[p << 1] = v[(p << 1) + 1] = v[p];
        v[p] = 0;
    }

    update(l, r, s, m, p << 1, c);
    update(l, r, m, t, (p << 1) + 1, c);

    d[p] = d[p << 1] + d[(p << 1) + 1];
}

int query(int l, int r, int s, int t, int p)
{
    if (r <= s || l >= t)
    {
        return 0;
    }

    if (l <= s && t <= r)
    {
        return d[p];
    }

    int m = (s + t) / 2;

    if (v[p])
    {
        d[p << 1] = b[p] * (m - s);
        d[(p << 1) + 1] = b[p] * (t - m);
        b[p << 1] = b[(p << 1) + 1] = b[p];
        v[p << 1] = v[(p << 1) + 1] = v[p];
        v[p] = 0;
    }

    return query(l, r, s, m, p << 1) + query(l, r, m, t, (p << 1) + 1);
}

void solve()
{
    int n;
    cin >> n;
    build(1, 1000002, 1);
    int mx = 0, mn = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        l++;
        r++;

        mx = max(mx, r);
        mn = min(mn, l);

        update(l, r, 1, 1000002, 1, 1);
    }

    int mx_you = 0, mx_wu = 0, mx_t = 0;

    for (int r = mn; r < mx; r++)
    {
        if (query(r, r + 1, 1, 1000002, 1) == 1)
        {
            mx_you = max(mx_you, ++mx_t);
        }
        else
        {
            mx_t = 0;
        }
    }
    mx_you = max(mx_you, mx_t);

    mx_t = 0;
    for (int r = mn; r < mx; r++)
    {
        if (query(r, r + 1, 1, 1000002, 1) == 0)
        {
            mx_wu = max(mx_wu, ++mx_t);
        }
        else
        {
            mx_t = 0;
        }
    }
    mx_wu = max(mx_wu, mx_t);

    cout << mx_you << ' ' << mx_wu << endl;
}

signed main()
{
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
