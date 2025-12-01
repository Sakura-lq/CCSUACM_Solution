#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

int f(int n)
{
    int res = 0;
    while (n)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    set<int> s;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > 9)
        {
            s.insert(i);
        }
    }

    while (q--)
    {
        int op;
        cin >> op;

        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            --l, --r;
            while (!s.empty())
            {
                auto it = s.lower_bound(l);
                int idx = *it;
                if (it == s.end() || idx > r)
                {
                    break;
                }
                a[idx] = f(a[idx]);
                s.erase(it);
                if (a[idx] > 9)
                {
                    s.insert(idx);
                }
                l = idx + 1;
            }
        }
        else
        {
            int x;
            cin >> x;
            --x;

            cout << a[x] << endl;
        }
    }

    return;
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