#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXN = 3e5 + 5;
int n;

int t[MAXN];

int lowbit(int x)
{
    return x & -x;
}

void update(int idx, int val)
{
    while (idx <= n)
    {
        t[idx] += val;
        idx += lowbit(idx);
    }
}

int query(int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += t[idx];
        idx -= lowbit(idx);
    }
    return sum;
}

void solve()
{
    int m;
    cin >> m;

    vector<tuple<int, int, int>> d(m);
    vector<int> date(m);

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        d[i] = {l, r, i + 1};
        date[i] = r;
    }

    sort(d.begin(), d.end(), [&](const tuple<int, int, int> &a, const tuple<int, int, int> &b){
        auto &[l1, r1, i1] = a;
        auto &[l2, r2, i2] = b;
        
        if(l1 != l2)
        {
            return l1 < l2;
        }

        return r1 > r2; 
    });

    sort(date.begin(), date.end());
    date.erase(unique(date.begin(), date.end()), date.end());

    auto getr = [&](int r) -> int
    {
        return lower_bound(date.begin(), date.end(), r) - date.begin() + 1;
    };

    n = date.size() + 1;

    for (int i = 0; i < m; i++)
    {
        get<1>(d[i]) = getr(get<1>(d[i]));
        update(get<1>(d[i]), 1);
    }

    int x = -1, y = -1;

    int j = 0;
    for (auto &a : d)
    {
        auto &[l, r, i] = a;

        update(r, -1);

        if (query(r) > 0)
        {
            x = j;
            break;
        }
        j++;
    }

    if (x == -1 && y == -1)
    {
        cout << "-1 -1" << endl;
        return;
    }

    for (int i = x + 1; i < m; i++)
    {
        if (get<1>(d[i]) <= get<1>(d[x]))
        {
            y = i;
            break;
        }
    }

    cout << get<2>(d[y]) << ' ' << get<2>(d[x]) << endl;
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