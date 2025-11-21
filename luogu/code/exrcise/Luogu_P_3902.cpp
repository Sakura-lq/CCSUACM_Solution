#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int t[100005];
int n;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= n)
    {
        t[k] = max(t[k], v);
        k += lowbit(k);
    }
}

int query(int k)
{
    int res = 0;
    while (k > 0)
    {
        res = max(res, t[k]);
        k -= lowbit(k);
    }
    return res;
}

void solve()
{
    int m;
    cin >> m;

    vector<int> date(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> date[i];
    }

    vector<int> sort_date(date);
    sort(sort_date.begin(), sort_date.end());
    sort_date.erase(unique(sort_date.begin(), sort_date.end()), sort_date.end());

    n = sort_date.size(); 
    int lis = 0;

    for (int i = 0; i < m; i++)
    {
        int idx = lower_bound(sort_date.begin(), sort_date.end(), date[i]) - sort_date.begin() + 1;

        int best = query(idx - 1); 
        int cur = best + 1;

        update(idx, cur);
        lis = max(lis, cur);
    }

    cout << m - lis << endl; 
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
