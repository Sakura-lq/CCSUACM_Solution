#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    int cnt = 0;
    for (int i = 1; i <= d; i++)
    {
        if (i % l == 0)
        {
            cnt++;
        }
        else if (i % m == 0)
        {
            cnt++;
        }
        else if (i % n == 0)
        {
            cnt++;
        }
        else if (i % k == 0)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}