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
    vector<int> nums_1(n);
    vector<int> nums_2(n);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        nums_1[i] = temp;
        nums_2[i] = temp;
    }
    sort(nums_1.begin(), nums_1.end());
    sort(nums_2.begin(), nums_2.end(), greater());
    int mx = 0;
    int mn = 0;
    for (int i = 0; i < n; i++) {
        if(mx >= nums_1[i])
            mx++;
        if(mx < nums_1[i])
            mx--;
        if(mn >= nums_2[i])
            mn++;
        if(mn < nums_2[i])
            mn--;
    }
    cout << mx << " " << mn;
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