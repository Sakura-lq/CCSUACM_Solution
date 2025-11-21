#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string s;
    cin >> s;

    if (s == "odd")
    {
        cout << 'o' << endl;
    }
    else
    {
        int cnt[26] = {};
        for (char x : s)
        {
            cnt[x - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == 1)
            {
                cout << char('a' + i) << endl;
                break;
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