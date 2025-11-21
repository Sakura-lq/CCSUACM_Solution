#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> s;
        int sum = 0;
        int max_elem = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s.insert(a[i]);
            sum += a[i];
            max_elem = max(max_elem, a[i]);
        }

        // 求 MEX
        int mex = 0;
        while (s.count(mex))
            mex++;

        if (k == 0)
        {
            cout << sum << endl;
            continue;
        }

        if (mex > max_elem)
        {
            // 所有元素小于 mex → 可以添加 mex
            sum += mex * min(k, 1LL); // 只加一次即可，数组稳定
            cout << sum << endl;
        }
        else
        {
            // 添加 ceil((mex + max_elem)/2)
            int new_elem = (mex + max_elem + 1) / 2;
            if (!s.count(new_elem))
                sum += new_elem;
            cout << sum << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
