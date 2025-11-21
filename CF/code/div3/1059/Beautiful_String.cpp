#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

bool f1(const string &s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

bool f2(const string &s)
{
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] < s[i - 1])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        string p = "", x = "";
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            {
                p += s[i];
                ans.push_back(i + 1);
            }
            else
            {
                x += s[i];
            }
        }

        if (f2(p) && f1(x))
        {
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << ' ';
            }
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
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
