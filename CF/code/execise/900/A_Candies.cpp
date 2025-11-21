#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    for (int k = 2; k <= 30; k++)
    {                                
        int x = (1LL << k) - 1; 
        if (n % x == 0)
        {
            cout << n / x << endl;
            return;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
