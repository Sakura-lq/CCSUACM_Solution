#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        set<int> fixed_values;
        int zeros = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                zeros++;
            }
            else
            {
                fixed_values.insert(a[i]);
            }
        }

        // 最大不同元素数 = 固定值数 + 自由0数，但不超过 n
        int ans = fixed_values.size() + zeros;
        ans = min(ans, (int)n);

        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
