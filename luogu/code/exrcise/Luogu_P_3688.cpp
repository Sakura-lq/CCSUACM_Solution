#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int inv2 = 499122177; // 1/2 mod 998244353

struct FenwickTree
{
    int n;
    vector<long long> tree; // 存储乘积，用long long避免中间溢出

    FenwickTree(int size) : n(size), tree(size + 1, 1) {} // 初始值为1

    // 单点更新：将第k个位置的值更新为 (1 - val) mod MOD
    void update(int k, long long val)
    {
        long long new_val = (1 - val + MOD) % MOD;                  // 确保非负
        long long mul = new_val * pow_mod(val, MOD - 2, MOD) % MOD; // 乘法因子：new_val = val * mul
        while (k <= n)
        {
            tree[k] = tree[k] * mul % MOD;
            k += k & -k;
        }
    }

    // 查询前缀积 [1, k]
    long long query_prefix(int k)
    {
        long long res = 1;
        while (k > 0)
        {
            res = res * tree[k] % MOD;
            k -= k & -k;
        }
        return res;
    }

    // 查询区间积 [L, R]
    long long query_range(int L, int R)
    {
        if (L > R)
            return 1;
        long long pre_R = query_prefix(R);
        long long pre_L1 = query_prefix(L - 1);
        // 区间积 = pre_R * inv(pre_L1) mod MOD
        return pre_R * pow_mod(pre_L1, MOD - 2, MOD) % MOD;
    }

    // 快速幂：计算 a^b mod mod
    long long pow_mod(long long a, long long b, long long mod)
    {
        long long res = 1;
        a %= mod;
        while (b > 0)
        {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    FenwickTree ft(n);
    vector<long long> p(n + 1, 1); // 维护每个位置当前的p[x]值

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int l, r;
            cin >> l >> r;
            // 遍历区间[l, r]，更新每个位置的p[x]
            for (int x = l; x <= r; ++x)
            {
                ft.update(x, p[x]);
                p[x] = (1 - p[x] + MOD) % MOD; // 更新p[x]的记录
            }
        }
        else
        {
            int L, R;
            cin >> L >> R;
            long long P = ft.query_range(L, R);
            long long ans = (1 + P) * inv2 % MOD;
            cout << ans << '\n';
        }
    }

    return 0;
}