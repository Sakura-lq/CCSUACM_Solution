#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string a, b;
    cin >> a >> b;

    auto tran = [&](string s) -> string
    {
        string t = "";
        for (char k : s)
        {
            t += tolower(k);
        }

        return t;
    };

    a = tran(a);
    b = tran(b);

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
        {
            cout << 1 << endl;
            return;
        }
        else if(a[i] < b[i])
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << 0 << endl;
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