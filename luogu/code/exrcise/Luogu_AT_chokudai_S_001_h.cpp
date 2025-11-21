#include<bits/stdc++.h>
using namespace std;
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
    while(k <= n)
    {
        t[k] = max(t[k], v);
        k += lowbit(k);
    }
}

int query(int k)
{
    int res = 0;
    while(k > 0)
    {
        res = max(res, t[k]);
        k -= lowbit(k);
    }

    return res;
}

void solve()
{
    cin >> n;

    vector<int>date(n);
    for(int i = 0; i < n; i++)
    {
        cin >> date[i];
    }

    for(int x : date)
    {
        update(x, query(x) + 1);
    }

    cout << query(n) << endl;
    return ;
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}