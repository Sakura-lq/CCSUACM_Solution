#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

vector<int> manacher(const string &s)
{
    string t = "#";
    for (char c : s)
    {
        t += c;
        t += '#';
    }

    int n = t.size();
    vector<int> d(n);
    for (int i = 0, l = 0, r = -1; i < n; i++)
    {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while (i - k >= 0 && i + k < n && t[i - k] == t[i + k])
        {
            k++;
        }
        d[i] = k--;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
    }
    return d;
}

string pref(const string &s)
{
    auto d = manacher(s);
    int n = s.size();
    int mx = 0;
    for (int i = 0; i < d.size(); i++)
    {
        int l = i - d[i] + 1, r = i + d[i] - 1;
        if (l == 0)
        {
            mx = max(mx, (r + 1) / 2);
        }
    }

    return s.substr(0, mx);
}

string suff(const string &s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());
    auto d = manacher(rs);
    int n = s.size();
    int mx = 0;
    for (int i = 0; i < d.size(); i++)
    {
        int l = i - d[i] + 1, r = i + d[i] - 1;
        if (l == 0)
        {
            mx = max(mx, (r + 1) / 2);
        }
    }

    string res = s.substr(n - mx, mx);
    return res;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.size();

    int k = 0;
    while (k < n / 2 && s[k] == s[n - k - 1]) 
    
        k++;
    }

    if (k == n / 2 || k == n)
    {
        cout << s << endl;
        return;
    }

    string mid = s.substr(k, n - 2 * k);

    string pre = pref(mid);
    string suf = suff(mid);

    if (pre.size() >= suf.size())
    {
        cout << s.substr(0, k) + pre + s.substr(n - k) << endl;
    }
    else
    {
        cout << s.substr(0, k) + suf + s.substr(n - k) << endl;
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
