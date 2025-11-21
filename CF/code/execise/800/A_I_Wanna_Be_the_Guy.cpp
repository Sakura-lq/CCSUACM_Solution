#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    set<int> st;

    int p, x;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> x;
        st.insert(x);
    }

    cin >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> x;
        st.insert(x);
    }

    cout << (st.size() == n ? "I become the guy." : "Oh, my keyboard!") << endl;
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