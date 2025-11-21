#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, hp;
    cin >> n >> hp;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> top(n + 1, 0);
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (pq.size() < i - 1)
        {
            pq.push(a[i]);
            sum += a[i];
        }
        else if (!pq.empty() && a[i] > pq.top())
        {
            sum += a[i] - pq.top();
            pq.pop();
            pq.push(a[i]);
        }
        top[i] = sum;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (pref[i] + top[i] >= hp)
        {
            ans = i;
            break;
        }
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