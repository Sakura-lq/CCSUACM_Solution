#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

vector<int> t;
int n;

int lowbit(int x)
{
    return x & -x;
}

void update(int k, int v)
{
    while(k <= n)
    {
        t[k] += v;
        k += lowbit(k);
    }
}

int query(int k)
{
    int res = 0;
    while(k > 0)
    {
        res += t[k];
        k -= lowbit(k);
    }

    return res;
}

void solve()
{
    int N;
    cin >> N;

    vector<int> date(N);
 
    for (int i = 0; i < N; i++)
    {
        cin >> date[i];
    }

    vector<int>st(date);
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());

    n = st.size();
    t.assign(n + 1, 0);

    int ans = 0;
    for(int i = N - 1; i >= 0; i--)
    {
        int idx = lower_bound(st.begin(), st.end(), date[i]) - st.begin() + 1;

        ans += query(idx - 1);

        update(idx, 1);
    }

    cout << ans << endl;
    return;
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