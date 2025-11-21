#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    string p, s;
    cin >> p >> s;

    int i = 0, j = 0;
    int n = p.size(), m = s.size();

    while (i < n && j < m)
    {
        if (p[i] != s[j])
        {
            cout << "NO" << endl;
            return;
        }

        char current = p[i];

        int cnt_p = 0;
        while (i < n && p[i] == current)
        {
            cnt_p++;
            i++;
        }

        int cnt_s = 0;
        while (j < m && s[j] == current)
        {
            cnt_s++;
            j++;
        }

        if (cnt_s < cnt_p || cnt_s > 2 * cnt_p)
        {
            cout << "NO" << endl;
            return;
        }
    }

    if (i < n || j < m)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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
