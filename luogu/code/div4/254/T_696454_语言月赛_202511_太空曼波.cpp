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
    vector<string> strs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> strs[i];
    }

    vector<unordered_set<string>> pre(n), suf(n);
    for (int i = 0; i < n; ++i)
    {
        string s = strs[i];
        for (int l = 1; l <= s.size(); ++l)
        {
            pre[i].insert(s.substr(0, l));
        }
        for (int l = 1; l <= s.size(); ++l)
        {
            suf[i].insert(s.substr(s.size() - l, l));
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        string s = strs[i];
        bool flag = false;
        for (int k = 1; k < s.size(); ++k)
        {
            string p = s.substr(0, k);
            string q = s.substr(k);

            bool flagp = false;
            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                {
                    continue;
                }
                if (pre[j].count(p))
                {
                    flagp = true;
                    break;
                }
            }
            if (!flagp)
            {
                continue;
            }

            bool flagq = false;
            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                {
                    continue;
                }
                if (suf[j].count(q))
                {
                    flagq = true;
                    break;
                }
            }
            if (flagq)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            ++cnt;
        }
    }

    cout << cnt << endl;

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