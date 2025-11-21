#include <bits/stdc++.h>
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
    int l = 1, r = n;
    bool flag = true; 
    for (int i = 0; i < n; i++)
    {
        if (flag)
        {
            cout << l++ << " ";
        }
        else
        {
            cout << r-- << " ";
        }
        flag = !flag;
    }
    cout << endl;

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