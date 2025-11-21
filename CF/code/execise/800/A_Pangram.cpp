#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    if (n < 26)
    {
        cout << "NO" << endl;
        return;
    }

    cin.ignore();
    string a;
    cin >> a;

    set<char> st;

    for (char x : a)
    {
        st.insert(tolower(x));
    }

    cout << (st.size() == 26 ? "YES" : "NO") << endl;
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