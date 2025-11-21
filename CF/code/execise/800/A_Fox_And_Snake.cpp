#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    bool flag = true;
    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << '#' << (i + 1 == m ? "\n" : "");
            }
        }
        else if(flag)
        {
            for (int i = 0; i < m - 1; i++)
            {
                cout << '.';
            }
            cout << '#' << endl;
            flag = false;
        }
        else
        {
            cout << '#';
            for (int i = 1; i < m; i++)
            {
                cout << '.' << (i + 1 == m ? "\n" : "");
            }
            flag = true;
        }
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