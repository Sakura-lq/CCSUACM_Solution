#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int MAXN = 2000005;

int trie[MAXN][52], cnt = 1;
int ed[MAXN], id = 1;

int t[100005], N;

int trans(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    return 26 + (c - 'A');
}

int insert(string s)
{
    int p = 1;
    for (char c : s)
    {
        int x = trans(c);
        if (!trie[p][x])
        {
            trie[p][x] = ++cnt;
        }
        p = trie[p][x];
    }
    ed[p] = id++;
    return ed[p];
}

int find_id(string s)
{
    int p = 1;
    for (char c : s)
    {
        int x = trans(c);
        if (!trie[p][x])
        {
            return 0;
        }
        p = trie[p][x];
    }
    return ed[p];
}

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v = 1)
{
    while (k <= N)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int getsum(int k)
{
    int sum = 0;
    while (k > 0)
    {
        sum += t[k];
        k -= lowbit(k);
    }
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    N = n;
    vector<string> teacher(n);
    for (int i = 0; i < n; i++)
    {
        cin >> teacher[i];
        insert(teacher[i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        string check;
        cin >> check;
        int x = find_id(check);
        ans += i - getsum(x);
        update(x);
    }

    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
