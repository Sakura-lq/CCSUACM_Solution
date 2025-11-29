#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    string t = "Timur";
    set<char> st;

    for (char x : t)
    {
        st.insert(x);
    }

    for (char x : s)
    {
        if (!st.count(x))
        {
            cout << "NO" << endl;
            return;
        }
        else
        {
            st.erase(x);
        }
    }

    cout << (st.size() == 0 ? "YES" : "NO") << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}