#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int cnt[10] = {};

    int n;
    string s;

    cin >> n >> s;

    for(char x : s)
    {
        cnt[x - '0']++;
    }

    cout << min(cnt[1], cnt[6] - 1) << endl;
    return ;
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