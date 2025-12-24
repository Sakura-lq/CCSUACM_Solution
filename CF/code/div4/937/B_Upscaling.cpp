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

    char s[2] = {'#', '.'};
    for (int i = 0; i < n; i++)
    {
        for (int q = 0; q < 2; q++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 2; k++)
                {
                    cout << s[j % 2];
                }
            }
            cout << endl;
        }
        swap(s[0], s[1]);
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