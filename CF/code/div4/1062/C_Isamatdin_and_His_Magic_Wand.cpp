#include<bits/stdc++.h>
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
    
    vector<int> nums(n, 0);
    int ou = 0, qi = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if(nums[i] % 2 == 0)
        {
            ou++;
        }
        else
        {
            qi++;
        }
    }

    if(ou && qi)
    {
        sort(nums.begin(), nums.end());
    }

    for(int x : nums)
    {
        cout << x << ' ';
    }
    cout << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}