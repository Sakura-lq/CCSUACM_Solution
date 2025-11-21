#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> b(m);
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }

    a[n - 1] = max(a[n - 1], b[m - 1] - a[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
        {
            int x = a[i + 1] + a[i];
            auto it = upper_bound(b.begin(), b.end(), x);
            if (it == b.begin())
            {
                cout << "NO" << endl;
                return;
            }
            --it;
            a[i] = *it - a[i];
        }
        else
        {
            auto it = upper_bound(b.begin(), b.end(), a[i] + a[i + 1]);
            if (it != b.begin())
            {
                --it;
                a[i] = max(a[i], *it - a[i]);
            }
        }

        if (a[i] > a[i + 1])
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    return;
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
