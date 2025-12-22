#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<string> g;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        g.push_back(s);
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == '1')
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            flag = true;
        }
        else if (cnt > 1)
        {
            break;
        }
    }
    reverse(g.begin(), g.end());
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == '1')
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            flag = true;
        }
        else if (cnt > 1)
        {
            break;
        }
    }

    cout << (flag ? "TRIANGLE" : "SQUARE") << endl;
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