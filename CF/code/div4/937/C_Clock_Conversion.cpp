#include <bits/stdc++.h>=
using namespace std;
#define i64 long long
#define d64 long double
#define endl '\n'
const i64 mod = 1e9 + 7;
const i64 N = 3e5 + 7;

void solve()
{
    string s;
    cin >> s;

    int h = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3));

    h += mm / 60;
    mm %= 60;
    h %= 24;

    if (h > 12)
    {
        h -= 12;
        cout << (h >= 10 ? to_string(h) : '0' + to_string(h)) + ':' + (mm >= 10 ? to_string(mm) : '0' + to_string(mm)) + " PM" << endl;
    }
    else if (h == 12)
    {
        cout << to_string(h) + ':' + (mm >= 10 ? to_string(mm) : '0' + to_string(mm)) + " PM" << endl;
    }
    else if (h == 0)
    {
        cout << "12:" + (mm >= 10 ? to_string(mm) : '0' + to_string(mm)) + " AM" << endl;
    }
    else
    {
        cout << (h >= 10 ? to_string(h) : '0' + to_string(h)) + ':' + (mm >= 10 ? to_string(mm) : '0' + to_string(mm)) + " AM" << endl;
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