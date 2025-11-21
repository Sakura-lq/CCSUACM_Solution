#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<pair<int, int>> ops(m);
    for (int i = 0; i < m; ++i)
    {
        int L, R;
        cin >> L >> R;
        ops[i] = {L - 1, R - 1}; // 转换为0-based
    }

    // 差分数组：记录每个位置的增量变化
    vector<int> diff(n + 2, 0); // diff[0..n+1]
    int res = 0;

    // 从右向左处理，确保右侧已满足条件
    for (int i = n - 2; i >= 0; --i)
    {
        // 计算当前位置的实际值（原始值 + 已累加的增量）
        int curr = a[i] + diff[i];
        // 计算右侧位置的实际值
        int next_val = a[i + 1] + diff[i + 1];

        // 需要补充的增量：使当前值 >= 右侧值
        int need = max(0LL, next_val - curr);
        if (need == 0)
            continue;

        // 寻找覆盖i且右边界最大的操作（贪心选择）
        int best_op = -1;
        int max_r = -1;
        for (int j = 0; j < m; ++j)
        {
            auto [L, R] = ops[j];
            if (L <= i && R >= i)
            { // 操作覆盖当前位置
                if (R > max_r)
                {
                    max_r = R;
                    best_op = j;
                }
            }
        }

        if (best_op == -1)
        { // 无可用操作，不可能完成
            cout << -1 << endl;
            return;
        }

        // 执行该操作need次
        res += need;
        auto [L, R] = ops[best_op];
        // 用差分记录区间增量
        diff[L] += need;
        if (R + 1 < n)
            diff[R + 1] -= need;
    }

    // 验证最终序列是否非递减
    int prev = a[0] + diff[0];
    for (int i = 1; i < n; ++i)
    {
        diff[i] += diff[i - 1]; // 累加差分得到实际增量
        int curr = a[i] + diff[i];
        if (curr < prev)
        {
            cout << -1 << endl;
            return;
        }
        prev = curr;
    }

    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
