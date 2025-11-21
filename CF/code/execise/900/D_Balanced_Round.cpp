#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> sorce(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sorce[i];
    }

    sort(sorce.begin(), sorce.end());

    int mx = 1;
    int len = 1;

    for (int i = 1; i < n; ++i)
    {
        if (sorce[i] - sorce[i - 1] <= k)
        {
            len++;
            mx = max(mx, len);
        }
        else
        {
            len = 1;
        }
    }

    cout << n - mx << endl;
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