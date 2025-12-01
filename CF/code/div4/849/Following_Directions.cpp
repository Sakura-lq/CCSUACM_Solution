#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    string s;
    int n;
    cin >> n >> s;

    bool flag = false;
    int x = 0, y = 0;

    for (char ch : s)
    {
        if (ch == 'L')
        {
            x--;
        }
        else if (ch == 'R')
        {
            x++;
        }
        else if (ch == 'U')
        {
            y++;
        }
        else
        {
            y--;
        }

        if(x == 1 && y == 1)
        {
            flag = true;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
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