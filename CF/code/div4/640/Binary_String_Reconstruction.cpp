#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    if (n1 == 0)
    {
        if (n0 > 0)
        {
            cout << string(n0 + 1, '0') << "\n";
        }
        else
        {
            cout << string(n2 + 1, '1') << "\n";
        }
        return;
    }

    string s;
    for (int i = 0; i <= n1; ++i)
    {
        s.push_back((i % 2 == 0) ? '1' : '0');
    }

    if (n0 > 0)
    {
        size_t pos0 = s.find('0');
        if (pos0 != string::npos)
        {
            s = s.substr(0, pos0) + string(n0 + 1, '0') + s.substr(pos0 + 1);
        }
    }

    if (n2 > 0)
    {
        size_t pos1 = s.find('1');
        if (pos1 != string::npos)
        {
            s = s.substr(0, pos1) + string(n2 + 1, '1') + s.substr(pos1 + 1);
        }
    }

    cout << s << "\n";

    return;
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
