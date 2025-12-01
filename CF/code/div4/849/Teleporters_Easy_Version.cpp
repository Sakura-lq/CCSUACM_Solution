#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] += (i + 1);
    }
    sort(a.begin(), a.end());
    int res = 0;
    for (int x : a)
    {
        if (x > c)
        {
            break;
        }
        c -= x;
        res++;
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