#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), cnt(n + 1), c(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 0; i <= n; i++)
    {
        if (cnt[i] % k)
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            cnt[i] /= k;
        }
    }

    int ans = 0;
    for (int l = 0, r = 0; r >= l && r < n; r++)
    {
        c[a[r]]++;
        while (c[a[r]] > cnt[a[r]])
        {
            c[a[l++]]--;
        }

        ans += r - l + 1;
    }

    cout << ans << endl;

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