#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string s;
    cin >> s;

    auto trans = [&](string a) -> string
    {
        string up = "";
        string down = "";

        int cnt1 = 0, cnt2 = 0;

        for(char ch : s)
        {
            if(ch != tolower(ch))
            {
                cnt1++;
            }
            up += tolower(ch);
        }

        for (char ch : s)
        {
            if (ch != toupper(ch))
            {
                cnt2++;
            }
            down += toupper(ch);
        }

        return cnt1 > cnt2 ? down : up;
    };

    cout << trans(s) << endl;
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}