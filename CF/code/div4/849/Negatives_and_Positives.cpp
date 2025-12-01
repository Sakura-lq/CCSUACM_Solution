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

    int cnt = 0, res = 0, mm = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        res += abs(a[i]);
        mm = min(mm, abs(a[i]));
        cnt += (a[i] < 0 ? 1 : 0);
    }

    cout << ((cnt & 1) ? res - 2 * mm : res) << endl;
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