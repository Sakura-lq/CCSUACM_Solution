#include <stdio.h>
#include <string.h>

#define MAX_N 8

// 生成下一个排列（模拟C++ next_permutation），返回1表示成功，0表示无下一个排列
int next_permutation(int *p, int n)
{
    // 从后找第一个p[i] < p[i+1]
    int i = n - 2;
    while (i >= 0 && p[i] >= p[i + 1])
    {
        i--;
    }
    if (i < 0)
        return 0;

    // 从后找第一个p[j] > p[i]
    int j = n - 1;
    while (p[j] <= p[i])
    {
        j--;
    }

    // 交换p[i]和p[j]
    int tmp = p[i];
    p[i] = p[j];
    p[j] = tmp;

    // 反转i+1到末尾的元素
    int left = i + 1, right = n - 1;
    while (left < right)
    {
        tmp = p[left];
        p[left] = p[right];
        p[right] = tmp;
        left++;
        right--;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int p[MAX_N];
    for (int i = 0; i < n; ++i)
    {
        p[i] = i + 1;
    }

    do
    {
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                printf(" ");
            }
            printf("%d", p[i]);
        }
        printf("\n");
        fflush(stdout);

        int res;
        scanf("%d", &res);
        if (res == 1)
        {
            return 0;
        }
    } while (next_permutation(p, n));

    return 0;
}