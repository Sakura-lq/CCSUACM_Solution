#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    vector<int>xin;

    auto f = [&](int x) -> int
    {
        int t = x;
        while(x)
        {
            if(x % 10 != 4 && x % 10 != 7)
            {
                return 0;
            }
            x /= 10;
        }

        return t;
    };

    for (int i = 1; i <= n; i++)
    {
        if(f(i))
        {
            xin.push_back(i);
        }
    }

    for (int i = 0; i < xin.size(); i++)
    {
        if(n % xin[i] == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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