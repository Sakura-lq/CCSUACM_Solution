#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MOD = 676767677;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ways = 1;
    for (int i = 0; i < n; i++)
    {
        bool canL = (i + a[i] <= n);     // L斗篷可行
        bool canR = (i - a[i] + 2 >= 1); // R斗篷可行

        if (!canL && !canR)
        {
            ways = 0;
            break;
        }
        else if (canL && canR)
        {
            ways = (ways * 2) % MOD;
        }
        // 否则只有一种选择，不改变ways
    }

    cout << ways << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
}
