#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    if (m >= n)
    {
        cout << 1 << endl;
        return;
    }

    vector<string> graph(n);
    for (int i = 0; i < n; i++)
    {
        cin >> graph[i];
    }

    set<string> st;

    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j <= n - m; j++)
        {
            string s;
            for (int x = i; x < i + m; x++)
            {
                s += graph[x].substr(j, m);
            }
            st.insert(s);
        }
    }

    cout << st.size() << endl;
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
