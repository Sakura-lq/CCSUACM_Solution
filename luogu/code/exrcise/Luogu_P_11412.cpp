#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAXN = 1e6;
int trie[MAXN][26], cnt;
int r[MAXN], v[MAXN];
vector<int> pre[MAXN];

void insert(string &s, int idx)
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
        pre[p].push_back(idx);
    }
}

int query(string &s)
{
    int res = 0;
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

    return p;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> r[i] >> v[i];
        cin >> s;
        insert(s, i);
    }

    for (int i = 0; i < m; i++)
    {
        int t;
        string s;
        cin >> t >> s;
        long long k = query(s), ans = 0;
        for (auto x : pre[k])
        {
            if (r[x] <= t)
            {
                ans += v[x];
            }
        }
        cout << ans << endl;
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