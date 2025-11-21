#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    auto f = [&](int x) -> bool
    {
        int cnt = 0;
        while (x)
        {
            if (x % 10 == 4 || x % 10 == 7)
            {
                cnt++;
            }
            x /= 10;
        }

        if(cnt == 0)
        {
            return false;
        }

        while (cnt)
        {
            if (cnt % 10 != 4 && cnt % 10 != 7)
            {
                return false;
            }
            cnt /= 10;
        }

        return true;
    };

    if (f(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

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