#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        while (i < s.size() && s[i] != '0')
        {
            i++;
            cnt++;
        }
        if (cnt >= 7)
        {
            cout << "YES" << endl;
            return;
        }
        cnt = 0;

        while (i < s.size() && s[i] != '1')
        {
            i++;
            cnt++;
        }
        if (cnt >= 7)
        {
            cout << "YES" << endl;
            return;
        }
        i--;
        cnt = 0;
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
    while (T--)
    {
        solve();
    }
    return 0;
}