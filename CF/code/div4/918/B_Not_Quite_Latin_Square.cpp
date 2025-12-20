#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int cnt[3]{};
    char x;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> x;
            if (x == '?')
            {
                continue;
            }
            cnt[x - 'A']++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (cnt[i] < 3)
        {
            cout << (char)('A' + i) << endl;
        }
    }
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