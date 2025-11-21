#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MAXN = 3e6;
int trie[MAXN][26], cnt;
int ed[MAXN];

void insert(string &s)
{
    int sz = s.length();
    int p = 0;

    for (int i = 0; i < sz; i++)
    {
        int c = s[i] - 'a';
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
    }

    ed[p]++;
}

int query(string &s)
{
    int sz = s.length();
    int p = 0;
    int res = 0;

    for (int i = 0; i < sz; i++)
    {
        int c = s[i] - 'a';
        res += ed[p];
        if (!trie[p][c])
        {
            return res;
        }
        p = trie[p][c];
    }

    return res + ed[p];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    cin.ignore();

    string s;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        insert(s);
    }

    while (m--)
    {
        cin >> s;
        cout << query(s) << endl;
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