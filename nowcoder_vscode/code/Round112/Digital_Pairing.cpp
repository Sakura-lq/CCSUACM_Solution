#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }

    int mask = 0;
    for (int b = 40; b >= 0; b--)
    {
        int k = mask | (1LL << b);
        int cnt = 0;
        for (auto x : a)
        {
            if ((x & k) == k)
            {
                cnt++;
            }
        }
        if (cnt >= n)
        {
            mask = k;
        }
    }

    cout << mask << '\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
