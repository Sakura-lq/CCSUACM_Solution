#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int t[200005];
int n;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= n)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int getsum(int k)
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
    cin >> n;
    vector<int> date(n);

    for (int i = 0; i < n; i++)
    {
        cin >> date[i];
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += getsum(date[i]);

        update(date[i], 1);
    }

    cout << ans << endl;

    fill(t, t + 200005, 0);
    return;
}

signed main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}