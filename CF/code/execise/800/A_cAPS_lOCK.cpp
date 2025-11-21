#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();

    bool flag1 = true;
    bool flag2 = true; 

    for (int i = 0; i < n; i++)
    {
        if (!isupper(s[i]))
        {
            flag1 = false;
        }
        if (i > 0 && !isupper(s[i]))
        {
            flag2 = false;
        }
    }

    if (flag1 || flag2)
    {
        for (int i = 0; i < n; i++)
        {
            if (isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
            else
            {
                s[i] = toupper(s[i]);
            }
        }
    }

    cout << s << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
