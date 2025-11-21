#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }

    int res = 0;
    vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        d[i] = a[i] ^ b[i];
        res ^= d[i];
    }

    if (res == 0)
    {
        cout << "Tie" << endl;
        return;
    }

    int k = 0;
    for (int bit = 30; bit >= 0; --bit)
    {
        if (res & (1 << bit))
        {
            k = bit;
            break;
        }
    }

    int q = -1;
    for (int i = n; i >= 1; --i)
    {
        if ((d[i] >> k) & 1)
        {
            q = i;
            break;
        }
    }

    if (q == -1)
    {
        cout << "Tie" << endl;
    }
    else if (q % 2 == 1)
    {
        cout << "Ajisai" << endl;
    }
    else
    {
        cout << "Mai" << endl;
    }
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