#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string s;
    cin >> s;

    while (s.find("WUB") != string::npos)
    {
        int pos = s.find("WUB");
        s.erase(pos, 3);
        s.insert(pos, 3, '*');
    }

    bool flag = true;
    for (char x : s)
    {
        if (x == '*' && flag)
        {
            flag = false;
            cout << ' ';
        }
        else if (x != '*')
        {
            cout << x;
            if (!flag)
            {
                flag = true;
            }
        }
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