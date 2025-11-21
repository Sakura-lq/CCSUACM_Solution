#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string s;
    cin >> s;
    vector<int> nums;

    for (char ch : s)
    {
        if (ch != '+')
        {
            nums.push_back(ch - '0');
        }
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        cout << (i + 1 != nums.size() ? '+' : ' ');
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