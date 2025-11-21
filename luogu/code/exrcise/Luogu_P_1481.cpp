#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MAXN = 150000;
int trie[MAXN][75], cnt;
int mx;
int ed[MAXN];

void insert(string s)
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

int find(string s)
{
    int sz = s.length();
    int p = 0;
    int ans = 0;

    for (int i = 0; i < sz; i++)
    {
        int c = s[i] - 'a';
        p = trie[p][c];
        ans += ed[p];
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;
    cin.ignore();

    vector<string> mi(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mi[i];

        insert(mi[i]);
    }

    for (string s : mi)
    {
        mx = max(mx, find(s));
    }

    cout << mx << endl;
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