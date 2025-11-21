#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int trie[31 * 100005][2], cnt;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int c = x >> i & 1;
        if (!trie[p][c])
        {
            trie[p][c] = ++cnt;
        }
        p = trie[p][c];
    }
}

int query(int x)
{
    int ans = 0;
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int c = x >> i & 1;
        if (trie[p][!c])
        {
            ans += (1 << i);
            p = trie[p][!c];
        }
        else
        {
            p = trie[p][c];
        }
    }

    return ans;
}
void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        insert(nums[i]);
    }

    int ans = 0;
    for (int x : nums)
    {
        ans = max(ans, query(x));
    }

    cout << ans << endl;

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