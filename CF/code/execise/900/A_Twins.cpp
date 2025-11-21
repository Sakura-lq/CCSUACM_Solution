#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> bins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> bins[i];
    }

    sort(bins.begin(), bins.end());

    vector<int> qian(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        qian[i + 1] = qian[i] + bins[i];
    }

    for (int i = n; i > 0; i--)
    {
        if (qian[n] - qian[i] > qian[i])
        {
            cout << n - i << endl;
            return;
        }
    }

    cout << n << endl;
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