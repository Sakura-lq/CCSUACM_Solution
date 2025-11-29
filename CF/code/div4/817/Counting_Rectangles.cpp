#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;
int a[1005][1005], pref[1005][1005];

void clear()
{
    for (int i = 0; i < 1005; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            a[i][j] = pref[i][j] = 0;
        }
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    clear();

    for (int i = 0; i < n; i++)
    {
        long long h, w;
        cin >> h >> w;
        a[h][w] += h * w;
    }
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << pref[hb - 1][wb - 1] - pref[hb - 1][ws] - pref[hs][wb - 1] + pref[hs][ws] << endl;
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