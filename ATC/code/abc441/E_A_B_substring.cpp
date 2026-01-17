#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

struct BIT
{
    int n;
    vector<i64> t;
    BIT(int n) : n(n), t(n + 1, 0) {}
    void update(int k, i64 v)
    {
        for (; k <= n; k += k & -k)
        {
            t[k] += v;
        }
    }
    i64 getsum(int k)
    {
        i64 s = 0;
        for (; k > 0; k -= k & -k)
        {
            s += t[k];
        }
        return s;
    }
};

void solve()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1];
        if (s[i - 1] == 'A')
        {
            pref[i]++;
        }
        else if (s[i - 1] == 'B')
        {
            pref[i]--;
        }
    }

    vector<int> st = pref;
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());

    auto f = [&](int x)
    {
        return lower_bound(st.begin(), st.end(), x) - st.begin() + 1;
    };

    BIT bit(st.size());
    i64 res = 0;

    bit.update(f(pref[0]), 1);

    for (int i = 1; i <= n; i++)
    {
        int idx = f(pref[i]);
        res += bit.getsum(idx - 1);
        bit.update(idx, 1);
    }

    cout << res << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}