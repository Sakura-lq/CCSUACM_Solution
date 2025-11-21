#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MAXN = 1e6;
int trie[MAXN][26];
bool ed[MAXN];
int cnt;

int n, l;

void insert(const string &s)
{
    int p = 0;
    for (char ch : s)
    {
        int c = ch - 'A';
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
    }

    ed[p] = true;
}

bool dfs(int d, int p, vector<vector<char>> &col, string &cur, string &ans)
{
    if (d == l)
    {
        if (!ed[p])
        {
            ans = cur;
            return true;
        }
        return false;
    }

    for (char c : col[d])
    {
        int x = c - 'A';
        cur.push_back(c);

        if (trie[p][x] == 0)
        {
            ans = cur;
            for (int j = d + 1; j < l; j++)
            {
                ans.push_back(col[j][0]);
            }
            return true;
        }

        if (dfs(d + 1, trie[p][x], col, cur, ans))
        {
            return true;
        }
        cur.pop_back();
    }

    return false;
}

void clear()
{
    memset(trie, 0, sizeof(trie));
    memset(ed, 0, sizeof(ed));
    cnt = 0;
}

void solve()
{
    int T;
    cin >> T;

    for (int k = 1; k <= T; k++)
    {
        cin >> n >> l;

        clear();

        vector<string> words(n);
        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
        }

        vector<set<char>> colset(l);
        for (auto &w : words)
        {
            for (int i = 0; i < l; i++)
            {
                colset[i].insert(w[i]);
            }
        }

        vector<vector<char>> col(l);
        for (int i = 0; i < l; i++)
        {
            col[i] = vector<char>(colset[i].begin(), colset[i].end());
        }

        for (auto &w : words)
        {
            insert(w);
        }

        string cur = "", ans = "";

        cout << "Case #" << k << ": " << (dfs(0, 0, col, cur, ans) ? ans : "-") << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
