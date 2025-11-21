#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, A, B;
    cin >> n >> A >> B;
    string s;
    cin >> s;

    vector<int> preA(n + 1, 0), preB(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        preA[i + 1] = preA[i] + (s[i] == 'a');
        preB[i + 1] = preB[i] + (s[i] == 'b');
    }

    int res = 0;
    int ra = 0, rb = 0;
    for (int l = 0; l < n; l++)
    {
        while (ra < n && preA[ra + 1] - preA[l] < A)
        {
            ra++;
        }
        while (rb < n && preB[rb + 1] - preB[l] < B)
        {
            rb++;
        }

        if (ra < n && ra < rb)
        {
            res += (rb - ra);
        }
    }

    cout << res << endl;
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