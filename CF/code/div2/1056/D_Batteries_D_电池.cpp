#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        vector<int> c(n + 1);
        iota(c.begin() + 1, c.end(), 1);

        bool found = false;

        for (int ref = 1; ref <= n && !found; ref++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i == ref)
                {
                    continue;
                }
                cout << ref << " " << i << "\n";
                cout.flush();

                int x;
                cin >> x;
                if (x == -1)
                {
                    exit(0);
                }
                if (x == 1)
                {
                    found = true;
                    break;
                }
            }
        }
    }

    return 0;
}
