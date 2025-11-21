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
    string s;
    cin >> s;

    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && flag)
        {
            s[i] = '1';
            flag = false;
        }
        else if (s[i] == '1' && !flag)
        {
            flag = true;
        }
        else if (s[i] == '1' && flag)
        {
            s[i] = '0';
        }
    }

    cout << s << endl;
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