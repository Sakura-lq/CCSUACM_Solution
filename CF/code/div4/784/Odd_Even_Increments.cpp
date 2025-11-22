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
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    bool a = nums[0] % 2;
    bool flag1 = true;
    for (int i = 0; i < n; i += 2)
    {
        if ((nums[i] % 2) != a)
        {
            flag1 = false;
            break;
        }
    }

    bool b = nums[1] % 2;
    bool flag2 = true;
    for (int i = 1; i < n; i += 2)
    {
        if ((nums[i] % 2) != b)
        {
            flag2 = false;
            break;
        }
    }

    cout << (flag1 && flag2 ? "YES" : "NO") << endl;
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