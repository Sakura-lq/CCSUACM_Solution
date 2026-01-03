#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    string s;
    cin >> s;

    set<char> st(s.begin(), s.end());

    if (st.size() == 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                swap(s[i], s[i - 1]);
                {
                    break;
                }
            }
        }
        cout << "YES" << endl << s << endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}