#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    if (pref[min(n, d)] >= c)
    {
        cout << "Infinity" << endl;
        return;
    }

    if (a[0] * d < c)
    {
        cout << "Impossible" << endl;
        return;
    }

    int left = 0, right = d + 1;

    while (left + 1 < right)
    {
        int mid = (left + right) >> 1;
        __int128 res = d / (mid + 1) * pref[min(n, mid + 1)] + pref[min(n, d % (mid + 1))];
        if (res >= c)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    cout << left << endl;
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
