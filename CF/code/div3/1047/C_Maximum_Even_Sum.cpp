#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int a, b;
    cin >> a >> b;

    int s = 0;
    int m = b;
    while (m % 2 == 0)
    {
        m /= 2;
        ++s;
    }

    int ans = -1;
    for (int t = s; t >= 0; --t)
    {
        int k = m * (1LL << t);
        bool left_odd = ((a & 1) && t == 0);
        bool right_odd = (s - t == 0);      
        if (left_odd == right_odd)
        { 
            ans = a * k + b / k;
            break;
        }
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
