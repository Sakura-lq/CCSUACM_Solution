#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int h, d;
    cin >> h >> d;

    int pos = 0;
    int hp = h;
    int dd = 1;
    int ans = 0;

    while (pos < d)
    {
        if (hp - dd >= 1)
        {
            hp -= dd;
            dd++;
            pos++;
        }
        else
        {
            hp++;
            dd = 1;
        }
        ans++;
    }

    cout << ans << endl;
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
