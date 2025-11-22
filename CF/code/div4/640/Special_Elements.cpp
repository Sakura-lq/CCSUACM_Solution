#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    unordered_map<int, int> hash;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        hash[nums[i]]++;
    }

    int res = 0;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + nums[i - 1];
        if (i > 1 && hash.count(pref[i]))
        {
            res += hash[pref[i]];
            hash[pref[i]] = 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i - 2; j++)
        {
            int x = pref[i] - pref[j];
            if (hash.count(x))
            {
                res += hash[x];
                hash[x] = 0;
            }
        }
    }

    cout << res << endl;
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