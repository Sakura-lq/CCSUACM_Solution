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
    cin >> n;

    set<pair<int, int>> st;

    for (int i = 0; i <= n / 2; i++)
    {
        if ((n - 2 * i) % 4 == 0)
        {
            st.insert({i, (n - 2 * i) / 4});
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
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}