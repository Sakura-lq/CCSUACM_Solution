#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXN = 1e6;
int trie[MAXN][64], cnt;
int pass[MAXN];
int hashs[256];

void insert(string &s)
{
    int sz = s.length();
    int p = 0;
    pass[p]++;

    for (int i = 0; i < sz; i++)
    {
        int c = hashs[(int)s[i]];
        if(!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
        pass[p]++;
    }
}

int serch(string &s)
{
    int sz = s.length();
    int p = 0;

    for (int i = 0; i < sz; i++)
    {
        int c = hashs[(int)s[i]];
        if (!trie[p][c])
        {
            return 0;
        }
        p = trie[p][c];
    }

    return pass[p];
}

void clear()
{
    for (int i = 0; i <= cnt; i++)
    {
        memset(trie[i], 0, sizeof(trie[i])); 
        pass[i] = 0;              
    }
    cnt = 0;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    cin.ignore();

    auto f = [&]() -> void
    {
        for (int i = 0; i < 10; i++)
        {
            hashs['0' + i] = i;
        }
        for (int i = 0; i < 26; i++)
        {
            hashs['a' + i] = 10 + i;
        }
        for (int i = 0; i < 26; i++)
        {
            hashs['A' + i] = 36 + i;
        }
    };

    f();

    string s;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        insert(s);
    }

    while(q--)
    {
        cin >> s;
        cout << serch(s) << endl;
    }

    clear();
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}