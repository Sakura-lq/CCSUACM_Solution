#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;
vector<int> a[4];

void clear()
{
    for (int i = 0; i < 4; i++)
    {
        a[i].clear();
    }
}

void solve()
{
    clear();

    int n;
    cin >> n;

    int x;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> s;

        int t = (s[0] - '0') + (s[1] - '0') * 2;
        a[t].push_back(x);
    }

    if (a[3].empty() && (a[1].empty() || a[2].empty()))
    {
        cout << -1 << endl;
        return;
    }

    sort(a[1].begin(), a[1].end());
    sort(a[2].begin(), a[2].end());
    sort(a[3].begin(), a[3].end());

    int t1 = a[1].empty() ? INT_MAX / 2 : a[1][0];
    int t2 = a[2].empty() ? INT_MAX / 2 : a[2][0];
    int t3 = a[3].empty() ? INT_MAX / 2 : a[3][0];

    cout << min(t1 + t2, t3) << endl;
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