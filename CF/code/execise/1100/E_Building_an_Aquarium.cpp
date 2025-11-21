#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + a[i];
    }

    int left = 1;
    int right = a.back() + x;

    while (left < right)
    {
        int mid = left + (right - left + 1) / 2;

        int idx = lower_bound(a.begin(), a.end(), mid) - a.begin();

        if (mid * idx - prefix[idx] <= x)
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << left << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
