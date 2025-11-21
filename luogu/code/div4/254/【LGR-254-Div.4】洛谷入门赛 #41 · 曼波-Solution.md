# 【LGR-254-Div.4】洛谷入门赛 #41 · 曼波


## Solution

### A.

---

C语言版本：
```c
#include <stdio.h>

int main()
{
    long long n, m, r, c;
    long long x1, y1, x2, y2;

    scanf("%lld%lld%lld%lld", &n, &m, &r, &c);
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

    long long res = ((x2 / r) - (x1 / r) + 1) * ((y2 / c) - (y1 / c) + 1);

    printf("%lld\n", res);

    return 0;
}
```

---

C++语言版本：
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    int x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    cout << ((x2 / r) - (x1 / r) + 1) * ((y2 / c) - (y1 / c) + 1) << endl;
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
```

---

### B.

---

C语言版本：
```c
#include <stdio.h>

int main()
{
    long long x1, x2, x3;
    long long y1, y2, y3;

    scanf("%lld%lld%lld", &x1, &x2, &x3);
    scanf("%lld%lld%lld", &y1, &y2, &y3);

    long long res = x1 * y1 + x2 * y2 + x3 * y3;
    if (res == 0)
    {
        printf("Orthogonal\n");
    }
    else
    {
        printf("Non-Orthogonal\n");
    }

    return 0;
}
```

---

C++语言版本：
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int x1, x2, x3;
    int y1, y2, y3;
    cin >> x1 >> x2 >> x3;
    cin >> y1 >> y2 >> y3;

    cout << (x1 * y1 + x2 * y2 + x3 * y3 == 0 ? "Orthogonal" : "Non-Orthogonal") << endl;
    return ;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```

---

### C.

---

C语言版本：
```c
#include <stdio.h>

int main()
{
    long long n, x;
    long long res, ans;

    scanf("%lld", &n);
    scanf("%lld", &x);

    res = x & 1;
    ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        scanf("%lld", &x);
        if (x & 1)
        { 
            if (res == 0)
            { 
                res = 1;
                ans++;
            }
        }
        else
        { 
            if (res == 1)
            { 
                res = 0;
                ans++;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
```

---

C++语言版本：
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n, x;
    cin >> n;
    
    cin >> x;

    int res = x & 1;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x;
        if(x & 1)
        {
            if(res == 0)
            {
                res = 1;
                ans++;
            }
        }
        else
        {
            if(res == 1)
            {
                res = 0;
                ans++;
            }
        }
    }

    cout << ans << endl;
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
```

---

### D.

---

C语言版本：
```c
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
```

---

C++语言版本：
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 505; 

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m, '.'));

    for (int j = 0; j < m; ++j)
    {
        int pos = j % 4;
        if (pos == 0 || pos == 2 || j == m - 1)
        {
            for (int i = 0; i < n; ++i)
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

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << g[i][j];
        }
        cout << '\n';
    }
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
```

---

### E.

---

C语言版本：
```c
#include <stdio.h>
#include <stdlib.h>

#define N 300007

long long lower_bound(long long arr[], long long len, long long x)
{
    long long left = 0, right = len - 1;
    long long res = len; 
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (arr[mid] >= x)
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}

int main()
{
    long long n;
    scanf("%lld", &n);

    long long nums[N];
    long long idx[N + 1];
    idx[0] = 0;

    for (long long i = 1; i <= n; i++)
    {
        long long l, r;
        scanf("%lld%lld", &l, &r);
        nums[i - 1] = l;
        idx[i] = idx[i - 1] + r;
    }

    long long q, x;
    scanf("%lld", &q);
    while (q--)
    {
        scanf("%lld", &x);
        long long pos = lower_bound(idx, n + 1, x);
        printf("%lld\n", nums[pos - 1]);
    }

    return 0;
}
```

---

C++语言版本：
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<int> nums;
    vector<int> idx(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;

        nums.push_back(l);
        idx[i] = r + idx[i - 1];
    }

    int q, x;
    cin >> q;
    while (q--)
    {
        cin >> x;
        cout << nums[lower_bound(idx.begin(), idx.end(), x) - idx.begin() - 1] << endl;
    }
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
```

---

### F.

---

C语言版本：
```c
#include <stdio.h>
#include <limits.h>

#define N 300007
#define MAX_KEY 400000

int main()
{
    long long n;
    scanf("%lld", &n);

    long long x[MAX_KEY];
    for (int i = 0; i < MAX_KEY; i++)
    {
        x[i] = INT_MAX;
    }

    long long mx = 0;
    for (long long i = 0; i < n; i++)
    {
        long long r, a, b;
        scanf("%lld%lld%lld", &r, &a, &b);
        long long key = a * 1000 + b;
        if (r < x[key])
        {
            x[key] = r;
        }
    }

    for (int i = 0; i < MAX_KEY; i++)
    {
        if (x[i] != INT_MAX && x[i] > mx)
        {
            mx = x[i];
        }
    }

    printf("%lld\n", mx);
    return 0;
}
```

---

C++语言版本：
```cpp
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(400000, INT_MAX);

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int r, a, b;
        cin >> r >> a >> b;

        x[a * 1000 + b] = min(r, x[a * 1000 + b]);
    }

    for(int q : x)
    {
        if(q != INT_MAX)
        {
            mx = max(mx, q);
        }
    }
    cout << mx << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```

---

### G.

---

C语言版本：
```c
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
```

---

C++语言版本：
```cpp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 3e5 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> strs[i];
    }

    vector<unordered_set<string>> pre(n), suf(n);
    for (int i = 0; i < n; ++i)
    {
        string s = strs[i];
        for (int l = 1; l <= s.size(); ++l)
        {
            pre[i].insert(s.substr(0, l));
        }
        for (int l = 1; l <= s.size(); ++l)
        {
            suf[i].insert(s.substr(s.size() - l, l));
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        string s = strs[i];
        bool flag = false;
        for (int k = 1; k < s.size(); ++k)
        {
            string p = s.substr(0, k);
            string q = s.substr(k);

            bool flagp = false;
            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                {
                    continue;
                }
                if (pre[j].count(p))
                {
                    flagp = true;
                    break;
                }
            }
            if (!flagp)
            {
                continue;
            }

            bool flagq = false;
            for (int j = 0; j < n; ++j)
            {
                if (j == i)
                {
                    continue;
                }
                if (suf[j].count(q))
                {
                    flagq = true;
                    break;
                }
            }
            if (flagq)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            ++cnt;
        }
    }

    cout << cnt << endl;

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
```

---

### H.

---

C语言版本：
```c
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
```

---

C++语言版本：
```cpp
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
```

---