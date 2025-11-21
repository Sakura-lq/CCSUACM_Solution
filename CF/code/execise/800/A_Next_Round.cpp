#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> peo(n);
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> peo[i];
        if (k == i + 1)
        {
            x = peo[i];
        }
    }

    int cnt = 0;
    for (int q : peo)
    {
        if (q >= x && q > 0)
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