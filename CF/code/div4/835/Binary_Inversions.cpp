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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int res = 0;
    int cnt1 = 0;
    for (int num : a)
    {
        if (num == 1)
        {
            cnt1++;
        }
        else
        {
            res += cnt1;
        }
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + (a[i - 1] == 1 ? 1 : 0);
    }

    vector<int> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + (a[i] == 0 ? 1 : 0);
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            mx = max(mx, suff[i + 1] - pref[i]);
        }
        else
        {
            mx = max(mx, pref[i] - suff[i + 1]);
        }
    }

    cout << res + mx << endl;
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