#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int m;
vector<int> t;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= m)
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
    int n;
    cin >> n;

    vector<int> date(n);
    for (int i = 0; i < n; i++)
    {
        cin >> date[i];
    }

    vector<int> sorted(date);
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    m = sorted.size();
    t.assign(m + 1, 0);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(sorted.begin(), sorted.end(), date[i]) - sorted.begin() + 1;

        res = max(res, i - query(idx));

        update(idx, 1);
    }

    cout << res + 1 << endl;

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