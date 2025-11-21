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

    unordered_map<int, int> hash;

    int res = 0;
    int x, pre = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pre ^= x;
        res += hash[pre]++;
    }

    cout << res << endl;
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