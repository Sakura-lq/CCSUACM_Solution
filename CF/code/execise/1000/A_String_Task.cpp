#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string s;
    cin >> s;

    auto f = [&](string s) -> string
    {
        string t = "";
        for (char &ch : s)
        {
            char x = tolower(ch);
            if (x == 'i' || x == 'a' || x == 'o' || x == 'u' || x == 'e' || x == 'y')
            {
                continue;
            }

            t += '.';
            t += x;
        }

        return t;
    };

    cout << f(s) << endl;

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