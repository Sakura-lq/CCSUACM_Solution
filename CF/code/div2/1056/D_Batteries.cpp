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

        bool found = false;

        for (int i = 1; i <= n && !found; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                cout << i << " " << j << "\n";
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
