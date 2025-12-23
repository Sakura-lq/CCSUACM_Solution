#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n == 1)
    {
        cout << a[0] << endl;
        return;
    }

    sort(a.begin(), a.end());
    i64 mm = a[0];
    i64 left = mm, right = a[1];
    i64 ans = 0;

    while (left <= right)
    {
        i64 mid = (left + right) / 2;
        auto it = lower_bound(a.begin() + 1, a.end(), mm + mid);
        if (it == a.begin() + 1)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << max(ans, mm) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}