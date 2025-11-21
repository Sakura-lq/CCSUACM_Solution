#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

struct
{
    int d[400000], a[100005], lazy[100005], v[100005];

    void build(int s, int t, int p)
    {
        if (s == t)
        {
            d[p] = a[s];
            return;
        }

        int m = s + ((t - s) >> 1);

        build(s, m, p << 1);
        build(m + 1, t, (p << 1) + 1);

        d[p] = d[p << 1] + d[(p << 1) + 1];
    }

    void update(int l, int r, int s, int t, int p, int c)
    {
        if (l <= s && t <= r)
        {
            d[p] = (t - s + 1) * c;
            lazy[p] = c;
            v[p] = 1;
            return;
        }

        int m = s + ((t - s) >> 1);

        if (v[p])
        {
            d[p << 1] = lazy[p] * (m - s + 1), d[(p << 1) + 1] = lazy[p] * (t - m);
            lazy[p << 1] = lazy[(p << 1) + 1] = lazy[p];
            v[p << 1] = v[(p << 1) + 1] = v[p];
            v[p] = 0;
        }

        if (l <= m)
        {
            update(l, r, s, m, p << 1, c);
        }

        if (r > m)
        {
            update(l, r, m + 1, t, (p << 1) + 1, c);
        }

        d[p] = d[p << 1] + d[(p << 1) + 1];
    }

    int getsum(int l, int r, int s, int t, int p)
    {
        if (l <= s && t <= r)
        {
            return d[p];
        }

        int m = s + ((t - s) >> 1);

        int sum = 0;

        if (v[p])
        {
            d[p << 1] = lazy[p] * (m - s + 1), d[(p << 1) + 1] = lazy[p] * (t - m);
            lazy[p << 1] = lazy[(p << 1) + 1] = lazy[p];
            v[p << 1] = v[(p << 1) + 1] = v[p];
            v[p] = 0;
        }

        if (l <= m)
        {
            sum += getsum(l, r, s, m, p << 1);
        }

        if (r > m)
        {
            sum += getsum(l, r, m + 1, t, (p << 1) + 1);
        }

        d[p] = d[p << 1] + d[(p << 1) + 1];

        return sum;
    }
} tree[2];

void solve()
{
    int L, N;
    cin >> L >> N;

    for (int i = 1; i <= L + 1; i++)
    {
        tree[0].a[i] = 1; 
        tree[1].a[i] = 1; 
    }

    tree[0].build(1, L + 1, 1);
    tree[1].build(1, L + 1, 1);

    int cut_tree = 0, cut_all = 0;
    while (N--)
    {
        int op, l, r;
        cin >> op >> l >> r;
        l++;
        r++;

        if (op == 0)
        {
            cut_tree += tree[0].getsum(l, r, 1, L + 1, 1);
            cut_all += tree[1].getsum(l, r, 1, L + 1, 1);
            tree[0].update(l, r, 1, L + 1, 1, 0);
            tree[1].update(l, r, 1, L + 1, 1, 0);
        }
        else
        {
            tree[1].update(l, r, 1, L + 1, 1, 1);
        }
    }

    int yu_sum = tree[1].getsum(1, L + 1, 1, L + 1, 1);
    int yu_shu = tree[0].getsum(1, L + 1, 1, L + 1, 1);

    cout << yu_sum - yu_shu << endl;
    cout << cut_all - cut_tree << endl;

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