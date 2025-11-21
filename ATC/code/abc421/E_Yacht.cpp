#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

void solve()
{
    vector<int> a(6);
    for (int i = 0; i < 6; ++i)
        cin >> a[i];

    // 计算每个数字出现的概率
    map<int, double> prob;
    for (int x : a)
        prob[x] += 1.0 / 6;

    // 所有可能出现的数字
    vector<int> vals;
    for (auto &p : prob)
        vals.push_back(p.first);

    // dp[k]表示还剩k个骰子未确定时的最大期望
    vector<double> dp(6, 0.0);

    // 第三次掷骰子后，没有更多选择
    for (int k = 0; k <= 5; ++k)
    {
        double max_exp = 0.0;
        // 尝试每个可能的X
        for (int x : vals)
        {
            double p = prob[x];
            double sum = 0.0;
            // 计算k个骰子中出现m个x的概率乘以得分x*m
            for (int m = 0; m <= k; ++m)
            {
                // 组合数C(k, m)
                double comb = 1.0;
                for (int i = 0; i < m; ++i)
                    comb *= (k - i) / (i + 1.0);
                // 概率：C(k,m) * p^m * (1-p)^(k-m)
                double pr = comb * pow(p, m) * pow(1 - p, k - m);
                sum += pr * x * m;
            }
            max_exp = max(max_exp, sum);
        }
        dp[k] = max_exp;
    }

    // 第二次掷骰子后的决策
    for (int kept = 0; kept <= 5; ++kept)
    {
        int k = 5 - kept; // 未保留的骰子数
        if (k == 0)
            continue;

        double max_exp = 0.0;
        // 尝试保留t个新掷出的骰子，t范围:0~k
        for (int t = 0; t <= k; ++t)
        {
            double sum = 0.0;
            // 对每个可能的X计算期望
            for (int x : vals)
            {
                double p = prob[x];
                // 计算掷k个骰子，保留t个x的概率
                for (int m = t; m <= k; ++m)
                {
                    // 从m个x中选择t个保留的组合数
                    double comb1 = 1.0;
                    for (int i = 0; i < t; ++i)
                        comb1 *= (m - i) / (i + 1.0);

                    // 从k个骰子中掷出m个x的组合数
                    double comb2 = 1.0;
                    for (int i = 0; i < m; ++i)
                        comb2 *= (k - i) / (i + 1.0);

                    double pr = comb1 * comb2 * pow(p, m) * pow(1 - p, k - m);
                    sum += pr * dp[k - t];
                }
            }
            max_exp = max(max_exp, sum);
        }
        dp[k] = max_exp;
    }

    // 第一次掷骰子后的决策
    double result = 0.0;
    // 尝试保留t个骰子，t范围:0~5
    for (int t = 0; t <= 5; ++t)
    {
        double sum = 0.0;
        for (int x : vals)
        {
            double p = prob[x];
            // 计算掷5个骰子，保留t个x的概率
            for (int m = t; m <= 5; ++m)
            {
                // 从m个x中选择t个保留的组合数
                double comb1 = 1.0;
                for (int i = 0; i < t; ++i)
                    comb1 *= (m - i) / (i + 1.0);

                // 从5个骰子中掷出m个x的组合数
                double comb2 = 1.0;
                for (int i = 0; i < m; ++i)
                    comb2 *= (5 - i) / (i + 1.0);

                double pr = comb1 * comb2 * pow(p, m) * pow(1 - p, 5 - m);
                sum += pr * dp[5 - t];
            }
        }
        result = max(result, sum);
    }

    cout << fixed << setprecision(10) << result << endl;
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
