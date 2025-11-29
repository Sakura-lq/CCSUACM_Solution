#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 2e5 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    int sum = 0;
    vector<int> q;

    for (int j = 0; j < n; ++j)
    {
        char c = s[j];
        int left = j;
        int right = n - 1 - j;

        if (c == 'L')
        {
            sum += left;
            if (right - left > 0)
            {
                q.push_back(right - left);
            }
        }
        else
        {
            sum += right;
            if (left - right > 0)
            {
                q.push_back(left - right);
            }
        }
    }

    sort(q.rbegin(), q.rend());
    int m = q.size();
    vector<int> prefix(m + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        prefix[i + 1] = prefix[i] + q[i];
    }

    vector<int> res(n);
    for (int k = 1; k <= n; ++k)
    {
        res[k - 1] = sum + prefix[min(k, m)];
    }

    for (int x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}