#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int MAXN = 5e7;
int trie[MAXN][2], cnt;
vector<int> ed[MAXN];

void insert(string &s, int idx)
{
    int p = 0;
    for (char ch : s)
    {
        int c = (ch == 'Y');
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
    }

    ed[p].push_back(idx);
}

int query(string &s)
{
    int p = 0;
    for (char ch : s)
    {
        int c = (ch == 'Y');
        if (!trie[p][c])
        {
            return 0;
        }
        p = trie[p][c];
    }
    return ed[p].size();
}

void solve()
{
    int N, K, M, F;
    cin >> N >> K >> M >> F;

    vector<string> card(N + 1, string(K, 'N'));
    for (int j = 0; j < K; ++j)
    {
        for (int t = 0; t < M; ++t)
        {
            int x;
            cin >> x;
            card[x][j] = 'Y';
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        insert(card[i], i);
    }

    for (int i = 0; i < F; ++i)
    {
        string s;
        cin >> s;

        int x = query(s);
        cout << (x == 1 ? ed[x][0] : 0) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
