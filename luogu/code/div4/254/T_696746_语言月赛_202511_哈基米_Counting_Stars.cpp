#include<bits/stdc++.h>
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
    vector<int> x(400000, INT_MAX);

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int r, a, b;
        cin >> r >> a >> b;

        x[a * 1000 + b] = min(r, x[a * 1000 + b]);
    }

    for(int q : x)
    {
        if(q != INT_MAX)
        {
            mx = max(mx, q);
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
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}