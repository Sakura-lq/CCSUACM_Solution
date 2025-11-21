#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int t[1000005];
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
    cin >> n;

    vector<int> date(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> date[i];
    }

    int ans = 0;

    for (int i = n; i > 0; i--)
    {
        ans += query(date[i]);

        update(date[i], 1);
    }

    if ((ans &= 1) != (n &= 1))
    {
        cout << "Um_nik" << endl;
    }
    else
    {
        cout << "Petr" << endl;
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