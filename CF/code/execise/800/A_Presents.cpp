#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int> ans(105, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ans[x] = i + 1;
    } 
    for(int x : ans)
    {
        if(x == 0)
        {
            continue;
        }
        cout << x << ' ';
    }
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