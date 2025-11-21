#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    auto check = [&](int m)
    {
        int last = -1, res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] - m <= last)
            {
                last = a[i] + m;
            }
            else
            {
                res = res + a[i] - m - last - 1;
                last = a[i] + m;
            }
        }
        res = res + max(0LL, x - last);
        return res >= k;
    };
    int l = -1, r = 2e9;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (check(m))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    if (l == -1)
    {
        for (int i = 0; i < k; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    int last = -1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - l <= last)
        {
            last = a[i] + l;
        }
        else
        {
            for (int j = last + 1; j < a[i] - l && k; j++, k--)
            {
                cout << j << " ";
            }
            last = a[i] + l;
        }
    }
    for (int j = last + 1; j <= x && k; j++, k--)
    {
        cout << j << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}