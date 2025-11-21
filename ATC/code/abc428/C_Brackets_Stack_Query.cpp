#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int q;
    cin >> q;
    vector<int> st;
    vector<int> st2;
    st.push_back(0);
    st2.push_back(0);

    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            char c;
            cin >> c;
            int cur = st.back() + (c == '(' ? 1 : -1);
            st.push_back(cur);
            st2.push_back(min(st2.back(), cur));
        }
        else
        {
            st.pop_back();
            st2.pop_back();
        }

        int mm1 = st.back();
        int mm2 = st2.back();
        cout << (mm1 == 0 && mm2 >= 0 ? "Yes" : "No") << endl;
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