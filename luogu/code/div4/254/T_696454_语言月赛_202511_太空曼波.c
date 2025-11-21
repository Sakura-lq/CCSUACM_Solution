#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 300007
#define MAX_STR_LEN 101 
#define MAX_N 101       
#define MAX_PREFIX 101

// 存储单个字符串的所有前缀
typedef struct
{
    char arr[MAX_PREFIX][MAX_STR_LEN];
    int cnt;
} StrSet;

// 检查字符串s是否在StrSet中存在
int set_contains(StrSet *set, const char *s)
{
    for (int i = 0; i < set->cnt; ++i)
    {
        if (strcmp(set->arr[i], s) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// 向StrSet中添加字符串（去重）
void set_insert(StrSet *set, const char *s)
{
    if (!set_contains(set, s))
    {
        strcpy(set->arr[set->cnt++], s);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char strs[MAX_N][MAX_STR_LEN];
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", strs[i]);
    }

    StrSet pre[MAX_N], suf[MAX_N];
    for (int i = 0; i < n; ++i)
    {
        pre[i].cnt = 0;
        suf[i].cnt = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        int len = strlen(strs[i]);
        char tmp[MAX_STR_LEN];

        for (int l = 1; l <= len; ++l)
        {
            strncpy(tmp, strs[i], l);
            tmp[l] = '\0';
            set_insert(&pre[i], tmp);
        }

        for (int l = 1; l <= len; ++l)
        {
            int start = len - l;
            strncpy(tmp, strs[i] + start, l);
            tmp[l] = '\0';
            set_insert(&suf[i], tmp);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int len = strlen(strs[i]);
        int flag = 0;
        char p[MAX_STR_LEN], q[MAX_STR_LEN];

        for (int k = 1; k < len; ++k)
        {
            strncpy(p, strs[i], k);
            p[k] = '\0';
            strcpy(q, strs[i] + k);

            int flagp = 0;
            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                {
                    continue;
                }
                if (set_contains(&pre[j], p))
                {
                    flagp = 1;
                    break;
                }
            }
            if (!flagp)
            {
                continue;
            }

            int flagq = 0;
            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                {
                    continue;
                }
                if (set_contains(&suf[j], q))
                {
                    flagq = 1;
                    break;
                }
            }
            if (flagq)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}