#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int cnt = 0;
    unordered_map<int, int> hash;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        if(hash.find(x) != hash.end())
        {
            cnt++;
        }
        else
        {
            hash[x]++;
        }
    }

    cout << cnt << endl;
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