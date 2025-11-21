#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int d[40000], a[10000], b[40000], v[40000];

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
        b[p] = c;
        v[p] = 1;
        return;
    }

    int m = s + ((t - s) >> 1);

    if (v[p])
    {
        d[p << 1] = b[p] * (m - s + 1);
        d[(p << 1) + 1] = b[p] * (t - m);
        b[p << 1] = b[(p << 1) + 1] = b[p];
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

int query(int l, int r, int s, int t, int p)
{
    if (l <= s && t <= r)
    {
        return d[p];
    }

    int m = s + ((t - s) >> 1);

    if (v[p])
    {
        d[p << 1] = b[p] * (m - s + 1);
        d[(p << 1) + 1] = b[p] * (t - m);
        b[p << 1] = b[(p << 1) + 1] = b[p];
        v[p << 1] = v[(p << 1) + 1] = v[p];
        v[p] = 0;
    }

    int res = 0;

    if (l <= m)
    {
        res += query(l, r, s, m, p << 1);
    }

    if (r > m)
    {
        res += query(l, r, m + 1, t, (p << 1) + 1);
    }

    return res;
}

void solve()
{
    int n;
    cin >> n;

    fill(a, a + n + 1, 1);
    build(1, n, 1);

    vector<int> nums(n + 1);
    vector<int> ans(n + 1);

    nums[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> nums[i];
    }

    auto find_k = [&](int k) -> int
    {
        int r = n, l = 1;
        while (l < r)
        {
            int mid = l + ((r - l) >> 1);
            if (query(1, mid, 1, n, 1) >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    };

    for (int i = n; i > 0; i--)
    {
        int k = nums[i] + 1;
        int pos = find_k(k);
        ans[i] = pos;
        update(pos, pos, 1, n, 1, 0);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
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