#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string s;
    getline(cin, s);

    set<char> st;
    for (char ch : s)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            st.insert(ch);
        }
    }

    cout << st.size() << endl;
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