#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> cnt(n + 1);
    for (int x = 1; x * x * 2 < n; x++)
    {
        for (int y = x + 1; x * x + y * y <= n; y++)
        {
            cnt[x * x + y * y]++;
        }
    }

    vector<int> ans;
    for (int i = 1; i < n + 1; i++)
    {
        if (cnt[i] == 1)
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}