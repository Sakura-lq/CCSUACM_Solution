#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int n;
int t[200005];

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while(k <= n)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

void add(int l, int r, int v)
{
    update(l, v);
    update(r + 1, -v);
}

int query(int k)
{
    int res = 0;
    while(k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }

    return res;
}

void solve()
{
    int q;

    cin >> n >> q;

    while(q--)
    {
        int l,r;
        cin >> l >> r;

        add(l, r, 1);
    }

    for(int i = 0; i < n; i++)
    {
        cout << query(i + 1) % 2;
    }

    cout << endl;
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