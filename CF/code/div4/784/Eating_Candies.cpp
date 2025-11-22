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

    vector<int> pref(n + 1);
    vector<int> suff(n + 1);

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + nums[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + nums[i];
    }

    int mx = 0;
    int i = 1, j = n;
    while (i <= j)
    {
        if (pref[i] == suff[j])
        {
            mx = max(mx, (pref[i] == suff[j] ? i + n - j : 0));
            i++;
            j--;
        }
        else if (pref[i] < suff[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    cout << mx << endl;
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