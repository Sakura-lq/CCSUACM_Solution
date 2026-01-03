#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, priority_queue<int>> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i] >> 2].push(-a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << -mp[a[i] >> 2].top() << " ";
        mp[a[i] >> 2].pop();
    }

    cout << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}