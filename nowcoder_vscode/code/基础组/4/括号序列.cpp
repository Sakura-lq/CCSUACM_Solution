#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    string s;
    cin >> s;

    stack<char> stk;
    for (char ch : s)
    {
        if (stk.empty() || (ch == '(' || ch == '{' || ch == '['))
        {
            stk.push(ch);
            continue;
        }
        char x = stk.top();
        stk.pop();
        if ((x == '(' && ch == ')') || (x == '{' && ch == '}') || (x == '[' && ch == ']'))
        {
            continue;
        }
        else
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << (stk.empty() ? "Yes" : "No") << endl;
    return;
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