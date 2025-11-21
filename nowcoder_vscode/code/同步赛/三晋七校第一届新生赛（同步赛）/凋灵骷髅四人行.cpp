#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    if (n < 4)
    {
        cout << n << '\n';
        for (int i = 1; i <= n; i++)
        {
            cout << i << ' ';
        }
        return;
    }
    vector<int> num, Q;
    num.push_back(n);
    while (num.back() >= 4)
    {
        auto x = num.back();
        int q = x / 5;
        int r = x % 5;
        num.push_back(q + ((r != 4) ? r : 0));
        Q.push_back(q);
    }
    cout << num.back() << '\n';
    if (num.back() == 0)
    {
        return;
    }
    vector<int> ans;
    for (int i = 1; i <= num.back(); i++)
    {
        int idx = i;
        for (int j = (int)num.size() - 1; j >= 0; j--)
        {
            if (idx <= Q[j])
            {
                idx *= 5;
            }
            else
            {
                idx = 5 * Q[j] + (idx - Q[j]);
            }
        }
        ans.push_back(idx);
    }
    for (auto i : ans)
    {
        cout << i << ' ';
    }
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