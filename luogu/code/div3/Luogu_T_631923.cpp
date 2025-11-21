#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 && y1 == y2)
    {
        cout << 0 << endl;
        return;
    }

    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    bool sr = (x1 == x2);
    bool sc = (y1 == y2);
    bool sd = (dx == dy);

    if (sr || sc || sd)
    {
        bool flag = false;
        if (sr)
        {
            flag = (dy == 1);
        }
        else if (sc)
        {
            flag = (dx == 1);
        }
        else
        {
            flag = (dx == 1);
        }

        if (flag)
        {
            cout << 1 << endl;
            return;
        }

        if (sr)
        {
            cout << (n > 2 ? 2 : 3) << endl;
        }
        else if (sc)
        {
            cout << (m > 2 ? 2 : 3) << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    else
    {
        cout << 2 << endl;
    }

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