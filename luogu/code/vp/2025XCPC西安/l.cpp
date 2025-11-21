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

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> ans(n);

    sort(nums.begin(), nums.end(), greater());

    vector<int> pre(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    int j = 1;
    for (int i = n; i >= 3; i--) {
        if(pre[i + j - 1] - pre[j] > nums[j-1])
            ans[i - 1] = pre[i + j - 1] - pre[j - 1];
        else {
            while(j < n - i + 1) {
                if (pre[i + j - 1] - pre[j] > nums[j - 1]){
                    ans[i - 1] = pre[i + j - 1] - pre[j - 1];
                    break;
                } else {
                    j++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i - 1] << " ";
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
    while (T--)
    {
        solve();
    }
    return 0;
}