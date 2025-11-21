#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef struct
{
    int l, r, h;
} Node;

int d[160005], v[160005], b[160005];

void build(int s, int t, int p)
{
    d[p] = 0;
    v[p] = 0;
    b[p] = 0;
    if (s == t)
    {
        return;
    }
    int m = s + ((t - s) >> 1);
    build(s, m, p << 1);
    build(m + 1, t, (p << 1) + 1);
}

void push(int p)
{
    if (v[p])
    {
        int val = b[p];
        int lc = p << 1, rc = lc + 1;
        d[lc] = max(d[lc], val);
        d[rc] = max(d[rc], val);
        b[lc] = max(b[lc], val);
        b[rc] = max(b[rc], val);
        v[lc] = v[rc] = 1;
        v[p] = 0;
    }
}

void update(int l, int r, int s, int t, int p, int c)
{
    if (l <= s && t <= r)
    {
        d[p] = max(d[p], c);
        b[p] = max(b[p], c);
        v[p] = 1;
        return;
    }
    push(p);
    int m = s + ((t - s) >> 1);
    if (l <= m)
    {
        update(l, r, s, m, p << 1, c);
    }
    if (r > m)
    {
        update(l, r, m + 1, t, (p << 1) + 1, c);
    }
    d[p] = max(d[p << 1], d[(p << 1) + 1]);
}

int query(int pos, int s, int t, int p)
{
    if (s == t)
    {
        return d[p];
    }
    push(p);
    int m = s + ((t - s) >> 1);
    if (pos <= m)
    {
        return query(pos, s, m, p << 1);
    }
    else
    {
        return query(pos, m + 1, t, (p << 1) + 1);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<Node> date(n);
    int mx = 0;

    for (int i = 0; i < n; i++)
    {
        int l, r, h;
        cin >> h >> l >> r;
        date[i] = {l, r, h};
        mx = max(mx, r);
    }

    int mx2 = mx * 2;
    build(1, mx2, 1);

    sort(date.begin(), date.end(), [&](const Node &a, const Node &b){
        if (a.h != b.h) return a.h < b.h;
        return a.l < b.l; 
    });

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto &[l, r, h] = date[i];
        int L = 2 * l + 1;
        int R = 2 * r - 1;
        ans += h - query(L, 1, mx2, 1);
        ans += h - query(R, 1, mx2, 1);
        update(L, R, 1, mx2, 1, h);
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
