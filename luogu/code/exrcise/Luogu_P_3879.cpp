#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXN = 5e3;
int trie[1005][MAXN][26], cnt = 1;
int pass[1005][MAXN], ed[1005][MAXN];

void insert(string s, int k)
{
    int sz = s.length();
    int p = 0;
    pass[k][0]++;

    for (int i = 0; i < sz; i++)
    {
        int c = s[i] - 'a';
        if (!trie[k][p][c])
        {
            trie[k][p][c] = ++cnt;
        }
        p = trie[k][p][c];
        pass[k][p]++;
    }

    ed[k][p]++;
}

int find(string s, int k)
{
    int sz = s.length();
    int p = 0;

    for (int i = 0; i < sz; i++)
    {
        int c = s[i] - 'a';
        if (!trie[k][p][c])
        {
            return 0;
        }
        p = trie[k][p][c];
    }

    return ed[k][p];
}
void solve()
{
    int n;

    cin >> n;
    cin.ignore();
    vector<string> book(n + 1);

    for (int i = 1; i <= n; i++)
    {
        getline(cin, book[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        string word;
        istringstream in(book[i]);
        getline(in, word, ' ');

        while (getline(in, word, ' '))
        {
            insert(word, i);
        }
        cnt = 1;
    }

    int m;
    cin >> m;
    cin.ignore();

    vector<vector<int>> ans;
    for (int j = 0; j < m; j++)
    {
        string check;
        cin >> check;

        ans.push_back({});
        for (int i = 1; i <= n; i++)
        {
            if (find(check, i))
            {
                ans[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
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