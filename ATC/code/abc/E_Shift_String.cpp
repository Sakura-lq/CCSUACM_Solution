#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

vector<int> f(const string &p)
{
    int n = p.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (p[i] == p[j])
        {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp(const string &s, const string &p)
{
    vector<int> res;
    vector<int> pi = f(p);
    int j = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        while (j > 0 && s[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == p[j])
        {
            j++;
        }
        if (j == p.size())
        {
            res.push_back(i - j + 1);
            j = pi[j - 1];
        }
    }
    return res;
}

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();

    if (count(a.begin(), a.end(), '1') != count(b.begin(), b.end(), '1'))
    {
        cout << -1 << endl;
        return;
    }

    string s = a + a;
    vector<int> matches = kmp(s, b);

    int ans = -1;
    for (int pos : matches)
    {
        if (pos < n)
        {
            ans = pos;
            break;
        }
    }
    cout << ans << endl;
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