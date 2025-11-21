#include <stdio.h>

#define N 505

int main()
{
    long long n, m;
    scanf("%lld%lld", &n, &m);

    char g[N][N];
    int i, j;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            g[i][j] = '.';
        }
    }

    for (j = 0; j < m; ++j)
    {
        int pos = j % 4;
        if (pos == 0 || pos == 2 || j == m - 1)
        {
            for (i = 0; i < n; ++i)
            {
                g[i][j] = 'x';
            }
        }
        else if (pos == 1)
        {
            g[n - 1][j] = 'x';
        }
        else if (pos == 3)
        {
            g[0][j] = 'x';
        }
    }

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            printf("%c", g[i][j]);
        }
        printf("\n");
    }

    return 0;
}