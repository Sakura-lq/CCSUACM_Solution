#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> nums;
    vector<int> idx(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;

        nums.push_back(l);
        idx[i] = r + idx[i - 1];
    }

    int q, x;
    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << nums[lower_bound(idx.begin(), idx.end(), x) - idx.begin() - 1] << endl;
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