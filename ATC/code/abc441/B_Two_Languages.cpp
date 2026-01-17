#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m, q;
    string s, t;

    cin >> n >> m >> s >> t >> q;

    unordered_set<char> sets(s.begin(), s.end());
    unordered_set<char> sett(t.begin(), t.end());

    while (q--)
    {
        string w;
        cin >> w;

        bool flags1 = true, flagt1 = true, flags2 = false, flagt2 = false;

        for (char c : w)
        {
            if (sets.count(c) == 0)
            {
                flags1 = false;
                flagt2 = true;
            }
            if (sett.count(c) == 0)
            {
                flagt1 = false;
                flags2 = true;
            }
        }

        if (flags1 && flags2)
        {
            cout << "Takahashi" << endl;
        }
        else if (flagt1 && flagt2)
        {
            cout << "Aoki" << endl;
        }
        else
        {
            cout << "Unknown" << endl;
        }
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}