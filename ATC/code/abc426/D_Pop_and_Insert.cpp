#include <bits/stdc++.h>
using namespace std;

int f(const string &s, char c, const vector<int> &pre, const vector<int> &suf)
{
    int n = s.size();
    vector<pair<int, int>> se;

    int l = -1;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == c)
        {
            if (l == -1)
            {
                l = i;
            }
        }
        else
        {
            if (l != -1)
            {
                se.emplace_back(l, i - 1);
                l = -1;
            }
        }
    }
    if (l != -1)
    {
        se.emplace_back(l, n - 1);
    }

    if (se.empty())
    {
        return n;
    }

    int mo = INT_MAX;
    for (auto &k : se)
    {
        int L = k.first;
        int R = k.second;

        int left_ops = L + pre[L];
        int right_ops = (n - 1 - R) + suf[R + 1];

        mo = min(mo, left_ops + right_ops);
    }

    return mo;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> pre0(n + 1, 0), pre1(n + 1, 0);
    for (int i = 0; i < n; ++i)
    {
        pre0[i + 1] = pre0[i] + (s[i] == '0');
        pre1[i + 1] = pre1[i] + (s[i] == '1');
    }

    vector<int> suf0(n + 1, 0), suf1(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
    {
        suf0[i] = suf0[i + 1] + (s[i] == '0');
        suf1[i] = suf1[i + 1] + (s[i] == '1');
    }

    int min0 = f(s, '0', pre0, suf0);
    int min1 = f(s, '1', pre1, suf1);

    cout << min(min0, min1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}
