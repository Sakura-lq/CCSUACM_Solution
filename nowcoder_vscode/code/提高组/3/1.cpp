#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n;i++)
    {
        cin >> nums[i];
    }

    unordered_map<int, int> hash;

    int ans = 0;
    int res = 0;
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        res += nums[right];
        if(hash.find(k - res) != hash.end())
        {
            ans += hash[k - ans];
        }
    }

    cout << ans << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}