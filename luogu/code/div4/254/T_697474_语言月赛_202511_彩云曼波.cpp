#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        p[i] = i + 1;
    }

    do
    {
        for (int i = 0; i < n; ++i)
        {
            cout << p[i] << " ";
        }
        cout << endl;

        int res;
        cin >> res;
        if (res == 1)
        {
            return 0;
        }
    } while (next_permutation(p.begin(), p.end()));

    return 0;
}