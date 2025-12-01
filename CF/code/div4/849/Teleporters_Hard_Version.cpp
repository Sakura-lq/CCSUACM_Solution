#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = {x + min(i + 1, n - i), x + (i + 1)};
    }

    sort(a.begin(), a.end());

    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + a[i].first;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int new_c = c - a[i].second;
        if (new_c < 0)
        {
            continue;
        }

        int l = 0, r = n - 1;
        int res = 0;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            int sum = 0;

            if (mid <= i)
            {
                sum = pref[mid];
            }
            else
            {
                sum = pref[mid + 1] - a[i].first;
            }

            if (sum <= new_c)
            {
                res = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        ans = max(ans, 1 + res);
    }

    cout << ans << endl;
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