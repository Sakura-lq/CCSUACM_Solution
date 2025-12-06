#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    string t = "codeforces";

    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        cnt += (s[i] != t[i] ? 1 : 0);
    }

    cout << cnt << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}