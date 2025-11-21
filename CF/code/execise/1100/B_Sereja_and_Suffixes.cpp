#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> nums(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    vector<int> pre(n + 2, 0);
    unordered_map<int, int> hash;

    for (int i = n; i > 0; i--)
    {
        if (hash.find(nums[i]) != hash.end())
        {
            pre[i] = pre[i + 1];
        }
        else
        {
            hash[nums[i]]++;
            pre[i] = pre[i + 1] + 1;
        }
    }

    while (m--)
    {
        int q;
        cin >> q;
        cout << pre[q] << endl;
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