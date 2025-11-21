#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    int x;
    int cnt[5] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cnt[x]++;
    }

    int ans = 0;

    ans += cnt[4];

    ans += cnt[3];
    cnt[1] = max(0LL, cnt[1] - cnt[3]);

    ans += cnt[2] / 2;
    cnt[2] %= 2;

    if (cnt[2] > 0)
    {   
        ans++;
        cnt[1] = max(0LL, cnt[1] - 2);
    }

    ans += (cnt[1] + 3) / 4;

    cout << ans << endl;

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