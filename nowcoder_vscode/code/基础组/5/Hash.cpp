#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
const int LEN = 6;

int getHash(const string &s, int mod, const vector<int> &pow26)
{
    int h = 0;
    for (int i = 0; i < LEN; i++)
    {
        h = (h * 26 + (s[i] - 'a')) % mod;
    }
    return h;
}

void solve()
{

    string s;
    int mod;
    while (cin >> s >> mod)
    {
        vector<int> pow26(LEN);
        pow26[LEN - 1] = 1 % mod;
        for (int i = LEN - 2; i >= 0; i--)
        {
            pow26[i] = (pow26[i + 1] * 26) % mod;
        }

        int h = getHash(s, mod, pow26);
        bool flag = false;

        for (int i = LEN - 1; i >= 0 && !flag; i--)
        {
            for (char c = s[i] + 1; c <= 'z'; c++)
            {
                string t = s;
                t[i] = c;
                for (int j = i + 1; j < LEN; j++)
                {
                    t[j] = 'a';
                }

                if (getHash(t, mod, pow26) == h)
                {
                    cout << t << endl;
                    flag = true;
                    break;
                }
            }
        }
        if (!flag)
        {
            cout << -1 << endl;
        }
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