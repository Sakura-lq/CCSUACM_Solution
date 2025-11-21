#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    int res = 0;
    int i = 0, j = 0;
    for (; i < n && j < m; i++, j++)
    {
        if(a[i] != b[j])
        {
            res++;
        }
    }

    cout << res + n + m - i - j << endl;
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