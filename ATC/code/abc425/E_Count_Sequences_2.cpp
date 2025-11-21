#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int MAXN = 5010;       
long long pre[MAXN][MAXN];

void solve()
{
    int T, M;
    cin >> T >> M;

    pre[0][0] = 1 % M;
    for (int n = 1; n < MAXN; ++n)
    {
        pre[n][0] = 1 % M;
        for (int k = 1; k <= n; ++k)
        {
            pre[n][k] = (pre[n - 1][k - 1] + pre[n - 1][k]) % M;
        }
    }

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> C(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> C[i];
        }

        long long ans = 1;
        int sum = 0;
        for (int c : C)
        {
            sum += c;
            ans = (ans * pre[sum][c]) % M; 
        }

        cout << ans << '\n';
    }
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}