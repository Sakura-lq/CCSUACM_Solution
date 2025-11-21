#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    char op;
    cin >> op;

    unordered_map<char, char> L;
    unordered_map<char, char> R;

    string s = "qwertyuiopasdfghjkl;zxcvbnm,./";
    for (int i = 0, j = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size())
        {
            L[s[i]] = s[i + 1];
        }
        if (i - 1 >= 0)
        {
            R[s[i]] = s[i - 1];
        }
    }

    cin.ignore();
    string t;
    cin >> t;

    for (char x : t)
    {
        if (op == 'L')
        {
            cout << L[x];
        }
        else
        {
            cout << R[x];
        }
    }

    cout << endl;

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