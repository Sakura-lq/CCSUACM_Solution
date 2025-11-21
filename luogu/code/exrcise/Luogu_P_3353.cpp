#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXX = 100000;
int cnt, root;
int a[MAXX * 2];
int ls[MAXX * 2], rs[MAXX * 2];

void update(int &p, int s, int t, int x, int f)
{
    if (!p)
    {
        p = ++cnt;
    }
    if (s == t)
    {
        a[p] += f;
        return;
    }
    int m = (s + t) >> 1;
    if (x <= m)
    {
        update(ls[p], s, m, x, f);
    }
    else
    {
        update(rs[p], m + 1, t, x, f);
    }
    a[p] = a[ls[p]] + a[rs[p]];
}

int query(int l, int r, int s, int t, int p)
{
    if (!p)
    {
        return 0;
    }
    if (l <= s && t <= r)
    {
        return a[p];
    }
    int m = (s + t) >> 1, ans = 0;
    if (l <= m)
    {
        ans += query(l, r, s, m, ls[p]);
    }
    if (r > m)
    {
        ans += query(l, r, m + 1, t, rs[p]);
    }
    return ans;
}

void solve()
{
    int n, w;
    cin >> n >> w;
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        int x, val;
        cin >> x >> val;
        k = max(k, x);
        update(root, 1, MAXX, x, val);
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int R = min(MAXX, i + w - 1);
        ans = max(ans, query(i, R, 1, MAXX, root));
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
