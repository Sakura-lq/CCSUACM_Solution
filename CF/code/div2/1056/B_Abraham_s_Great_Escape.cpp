#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    int n, k;
    cin >> n >> k;

    if (n * n - k == 1)
    {
        cout << "NO" << endl;
        return;
    }

    vector<vector<char>> grid(n, vector<char>(n, '#'));
    int cnt = 0;
    bool flag = false;
    int i, j;

    for (i = 0; i < n; i++)
    {
        if (cnt == k)
        {
            flag = true;
            break;
        }
        for (j = 0; j < n; j++)
        {
            grid[i][j] = 'U';
            cnt++;
            if (cnt == k)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }

    flag = true;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            if (grid[x][y] != '#')
            {
                continue;
            }
            if (x == n - 1 && flag)
            {
                grid[x][y] = 'R';
                flag = false;
            }
            else if (x == n - 1)
            {
                grid[x][y] = 'L';
            }
            else
            {
                grid[x][y] = 'D';
            }
        }
    }

    cout << "YES" << endl;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            cout << grid[row][col];
        }
        cout << endl;
    }
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
