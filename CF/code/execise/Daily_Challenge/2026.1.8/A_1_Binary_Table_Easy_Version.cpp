#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    string arr[n];
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '1')
            {
                cnt++;
            }
        }
    }

    cout << 3 * cnt << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '1')
            {
                int cx = i + 1;
                int cy = j + 1;
                int px = (cx < n) ? cx + 1 : cx - 1;
                int py = (cy < m) ? cy + 1 : cy - 1;
                cout << px << ' ' << cy << ' ';
                cout << cx << ' ' << py << ' ';
                cout << cx << ' ' << cy << endl;
                cout << px << ' ' << cy << ' ';
                cout << px << ' ' << py << ' ';
                cout << cx << ' ' << cy << endl;
                cout << cx << ' ' << py << ' ';
                cout << px << ' ' << py << ' ';
                cout << cx << ' ' << cy << endl;
            }
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}