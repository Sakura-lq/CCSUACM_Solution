#include <bits/stdc++.h>
using namespace std;
#define double long double
#define endl '\n'

const int MAXN = 2e6;
int trie[MAXN][64], cnt;
int len;
int pass[MAXN], ed[MAXN], sorce[MAXN];
int hashs[256];

int found(string &s)
{
    int p = 0;
    int sz = s.length();

    for (int i = 0; i < sz; i++)
    {
        int c = hashs[(int)s[i]];
        if (!trie[p][c])
        {
            return 0;
        }
        p = trie[p][c];
    }

    
    return (ed[p] == 0 ? 0 : sorce[p]);
}

void insert(string &s, int x)
{

    int p = 0;
    int sz = s.length();

    if (found(s))
    {
        for (int i = 0; i < sz; i++)
        {
            int c = hashs[(int)s[i]];
            p = trie[p][c];
        }

        sorce[p] = x;
        return;
    }

    pass[p]++;

    for (int i = 0; i < sz; i++)
    {
        int c = hashs[(int)s[i]];
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
        pass[p]++;
    }

    ed[p]++;
    sorce[p] = x;
    len++;
}

bool deleted(string &s)
{
    if (!found(s))
    {
        return false;
    }

    int p = 0;
    int sz = s.length();
    pass[p]--;

    for (int i = 0; i < sz; i++)
    {
        int c = hashs[(int)s[i]];
        if (--pass[trie[p][c]] == 0)
        {
            trie[p][c] = 0;
            len--;
            return true;
        }
        p = trie[p][c];
    }

    ed[p]--;
    len--;

    return true;
}

void solve()
{
    int n;
    cin >> n;

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

    while (n--)
    {
        int op;
        cin >> op;
        string name, so;
        if (op == 1)
        {
            cin >> name >> so;

            insert(name, stoi(so));
            cout << "OK" << endl;
        }
        else if (op == 2)
        {
            cin >> name;

            int x = found(name);

            if (x)
            {
                cout << x << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else if (op == 3)
        {
            cin >> name;

            if (deleted(name))
            {
                cout << "Deleted successfully" << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
        }
        else
        {
            cout << len << endl;
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