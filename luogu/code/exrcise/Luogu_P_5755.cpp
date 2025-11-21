#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXN = 1e5;
int trie[MAXN][26], cnt = 1;

void insert(string &s)
{
    int sz = s.length();
    int p = 1;
    for (int i = 0; i < sz; i++)
    {
        int c = s[i] - 'A';
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
    }
}

void solve()
{
    string word;
    while (getline(cin, word))
    {
        insert(word);
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