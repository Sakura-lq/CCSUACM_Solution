#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

int t[100005];
int m;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while (k <= m)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int getsum(int k)
{
    int res = 0;
    while (k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }
    return res;
}

int find_mid(int k)
{
    int l = 1, r = m, ans = m;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (getsum(mid) >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    
    return ans; 
}

void solve()
{
    int n;
    cin >> n;

    vector<int> date(n);
    for (int i = 0; i < n; i++)
    {
        cin >> date[i];
    }

    vector<int> sorted(date);
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    m = sorted.size() + 1; 

    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(sorted.begin(), sorted.end(), date[i]) - sorted.begin() + 1;

        update(idx, 1);

        if ((i + 1) % 2)
        {
            cout << sorted[find_mid((i + 2) / 2) - 1] << endl; 
        }
    }
}

signed main()
{
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
