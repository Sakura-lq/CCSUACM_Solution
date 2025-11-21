#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m; 

    int res = 0;
    int cur = 1; 

    vector<int> tasks(m); 
    for (int i = 0; i < m; i++)
    {
        cin >> tasks[i];
    }

    for (int i = 0; i < m; i++)
    {
        int target = tasks[i];
        if (target >= cur)
        {
            res += target - cur;
        }
        else
        {
            res += (n - cur) + target;
        }
        cur = target; 
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
    while (T--)
    {
        solve();
    }
    return 0;
}
