#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    cin >> s;

    int ans = 0;
    for (char ch : s)
    {
        if (ch == 'A')
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }

    if (ans > 0)
    {
        cout << "Anton" << endl;
    }
    else if (ans < 0)
    {
        cout << "Danik" << endl;
    }
    else
    {
        cout << "Friendship" << endl;
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