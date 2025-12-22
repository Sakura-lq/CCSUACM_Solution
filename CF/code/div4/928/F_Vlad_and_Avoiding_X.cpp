#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

vector<pair<int, int>> odd, even;

bool check(int g[7][7], bool odd)
{
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            if (g[i][j] && ((i + j) % 2 == odd))
            {
                if (g[i - 1][j - 1] && g[i - 1][j + 1] && g[i + 1][j - 1] && g[i + 1][j + 1])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool f(int g[7][7], int left, int idx, vector<pair<int, int>> &gragh, int op)
{
    if (left == 0)
    {
        return check(g, op);
    }
    if (idx == gragh.size())
    {
        return false;
    }
    bool flag = false;
    flag |= f(g, left, idx + 1, gragh, op);
    g[gragh[idx].first][gragh[idx].second] ^= 1;
    flag |= f(g, left - 1, idx + 1, gragh, op);
    g[gragh[idx].first][gragh[idx].second] ^= 1;
    return flag;
}

void solve()
{
    int g[7][7];
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            char c;
            cin >> c;
            g[i][j] = c == 'B' ? 1 : 0;
        }
    }

    int res = 0;
    for (int i = 0; i <= 4; i++)
    {
        if (f(g, i, 0, odd, 1))
        {
            res += i;
            break;
        }
    }

    for (int i = 0; i <= 4; i++)
    {
        if (f(g, i, 0, even, 0))
        {
            res += i;
            break;
        }
    }

    cout << res << endl;

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if ((i + j) % 2)
            {
                odd.emplace_back(i, j);
            }
            else
            {
                even.emplace_back(i, j);
            }
        }
    }

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
