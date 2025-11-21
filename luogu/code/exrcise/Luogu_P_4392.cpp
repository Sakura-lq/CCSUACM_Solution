#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int N = 1000000 + 5;
vector<int> date;
int n;
int t1[N], t2[N];

int lowbit(int x)
{
    return x & -x;
}

void update_mx(int x, int v)
{
    date[x - 1] = v;
    for (int i = x; i <= n; i += lowbit(i))
    {
        t1[i] = date[i - 1];
        for (int j = 1; j < lowbit(i); j *= 2)
        {
            t1[i] = max(t1[i], t1[i - j]);
        }
    }
}

void update_mm(int x, int v)
{
    date[x - 1] = v;
    for (int i = x; i <= n; i += lowbit(i))
    {
        t2[i] = date[i - 1];
        for (int j = 1; j < lowbit(i); j *= 2)
        {
            t2[i] = min(t2[i], t2[i - j]);
        }
    }
}

int getmax(int l, int r)
{
    int ans = LLONG_MIN;
    while (r >= l)
    {
        ans = max(ans, date[r - 1]);
        --r;
        for (; r - lowbit(r) >= l; r -= lowbit(r))
        {
            ans = max(ans, t1[r]);
        }
    }
    return ans;
}

int getmin(int l, int r)
{
    int ans = LLONG_MAX;
    while (r >= l)
    {
        ans = min(ans, date[r - 1]);
        --r;
        for (; r - lowbit(r) >= l; r -= lowbit(r))
        {
            ans = min(ans, t2[r]);
        }
    }
    return ans;
}

int query(int l, int r)
{
    return getmax(l, r) - getmin(l, r);
}

void solve()
{
    int m, c;
    cin >> n >> m >> c;

    date.assign(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> date[i];
    }

    for (int i = 0; i < n; i++)
    {
        update_mm(i + 1, date[i]);
        update_mx(i + 1, date[i]);
    }

    bool flag = false;
    for (int i = 0; i + m - 1 < n; i++)
    {
        int j = i + m - 1;
        if (query(i + 1, j + 1) <= c)
        {
            cout << i + 1 << endl;
            flag = true;
        }
    }

    if (!flag)
    {
        cout << "NONE" << endl;
    }

    return;
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
