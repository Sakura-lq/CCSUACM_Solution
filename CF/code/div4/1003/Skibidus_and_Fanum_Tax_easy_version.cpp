#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 9;
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

    int b;
    cin >> b;

    if (n == 1)
    {
        cout << "YES" << endl;
        return;
    }

    a[n - 1] = max(a[n - 1], b - a[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
        {
            if (b - a[i] > a[i + 1])
            {
                cout << "NO" << endl;
                return;
            }
            a[i] = b - a[i];
        }
        else
        {
            if (b - a[i] <= a[i + 1])
            {
                a[i] = max(a[i], b - a[i]);
            }
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