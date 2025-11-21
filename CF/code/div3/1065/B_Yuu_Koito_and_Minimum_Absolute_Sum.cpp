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
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int ans;
    if (a[0] != -1 && a[n - 1] != -1)
    {
        ans = llabs(a[n - 1] - a[0]);
    }
    else
    {
        ans = 0;
    }

    if (ans == 0)
    {
        if (a[0] == -1 && a[n - 1] == -1)
        {
            a[0] = 0;
            a[n - 1] = 0;
        }
        else if (a[0] == -1)
        {
            a[0] = a[n - 1];
        }
        else if (a[n - 1] == -1)
        {
            a[n - 1] = a[0];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == -1)
        {
            a[i] = 0;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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