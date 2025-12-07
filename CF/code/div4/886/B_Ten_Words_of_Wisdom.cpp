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
    vector<pair<int, int>> x;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a <= 10)
        {
            x.push_back({b, i + 1});
        }
    }

    sort(x.begin(), x.end());
    cout << x.back().second << endl;
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