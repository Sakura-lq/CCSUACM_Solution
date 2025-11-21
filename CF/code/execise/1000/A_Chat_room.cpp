#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    string target = "hello";
    int pos = 0;

    for (char ch : s)
    {
        if (ch == target[pos])
        {
            pos++;
            if (pos == target.length())
            {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
