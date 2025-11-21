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

    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            ans.push_back(i);
            if(i * i != n)
            {
                ans.push_back(n / i);
            }
        }
    }

    sort(ans.begin(), ans.end());

    int res = 0;
    for (int i = 1; i < ans.size(); i++)
    {
        if(ans[i] - ans[i - 1] == 1)
        {
            res++;
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
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}