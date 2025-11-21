#include <bits/stdc++.h>
using namespace std;
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    for (int a = 2; a * a * a <= n; ++a)
    {
        if (n % a != 0)
        {
            continue;
        }

        int nxt = n / a;
        for (int b = a + 1; b * b <= nxt; ++b)
        {
            if (nxt % b == 0)
            {
                int c = nxt / b;
                if (c > b)
                {
                    cout << "YES" << endl;
                    cout << a << " " << b << " " << c << endl;
                    return;
                }
            }
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}