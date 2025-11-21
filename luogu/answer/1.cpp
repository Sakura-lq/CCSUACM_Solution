#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int cnt[100005];
int pref[100007];

static void f()
{
    for (int i = 0; i < 100005; i++)
    {
        if (sqrtl(i) * sqrtl(i) == i)
        {
            cnt[i]++;
        }
    }

    for (int i = 1; i <= 100005; i++)
    {
        pref[i] = pref[i - 1] + cnt[i];
    }
}

void solve()
{
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;

        cout << pref[(int)sqrtl(r)] - pref[(int)sqrtl(l - 1)] << endl;
    }
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    f();
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}