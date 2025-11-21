#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int trie[1000000][26], cnt;
int flag[1000000];

void insert(string &s)
{
    int p = 0;
    int sz = s.length();

    for (int i = 0; i < sz; i++)
    {
        int c = s[i] - 'a';
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }

        p = trie[p][c];
    }
    flag[p] = 1;

    return;
}

int find(string &s)
{
    int p = 0;
    int sz = s.length();
    for (int i = 0; i < sz; i++)

    {
        int c = s[i] - 'a';
        if (!trie[p][c])
        {
            return 0;
        }

        p = trie[p][c];
    }

    if(flag[p] == 1)
    {
        flag[p]++;
        return 1;
    }

    return flag[p];
}

void solve()
{
    int n;
    cin >> n;

    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }

    int m;
    cin >> m;

    while (m--)
    {
        cin.ignore();
        string s;
        cin >> s;

        int k = find(s);
        if (k == 0)
        {
            cout << "WRONG" << endl;
        }
        else if (k == 1)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "REPEAT" << endl;
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