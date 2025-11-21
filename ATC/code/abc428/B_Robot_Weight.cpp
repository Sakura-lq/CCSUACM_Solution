#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int X;
    cin >> X;

    int N;
    cin >> N;
    vector<int> W(N + 1); 
    for (int i = 1; i <= N; ++i)
    {
        cin >> W[i];
    }

    vector<bool> vis(N + 1, false);

    int Q;
    cin >> Q;
    int cur = X; 
    while (Q--)
    {
        int P;
        cin >> P;

        if (vis[P])
        {
            cur -= W[P];
            vis[P] = false;
        }
        else
        {
            cur += W[P];
            vis[P] = true;
        }

        cout << cur << endl;
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