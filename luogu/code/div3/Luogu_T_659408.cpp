#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 计算字符串在长度上限 limit 内的最大 CDNL 子串数量和对应前/后缀匹配长度
pair<int, int> getMaxCntAndEdge(const string &str, int limit, bool getPrefix)
{
    string target = "CDNL";
    int n = str.size();
    int maxCnt = 0, edgeLen = 0;

    // 状态机：匹配 CDNL
    int match = 0, cnt = 0;
    int l = 0; // 滑动窗口左端点
    for (int r = 0; r < n; r++)
    {
        if (str[r] == target[match])
        {
            match++;
            if (match == 4)
            {
                cnt++;
                match = 0;
            }
        }
        else
        {
            if (str[r] == target[0])
                match = 1;
            else
                match = 0;
        }

        // 保持窗口长度 <= limit
        if (r - l + 1 > limit)
        {
            // 移除左端点对 match 的影响
            // 直接重算 match 比较安全，因为 CDNL 长度固定 4
            match = 0;
            cnt = 0;
            for (int i = r - limit + 1; i <= r; i++)
            {
                if (str[i] == target[match])
                {
                    match++;
                    if (match == 4)
                    {
                        cnt++;
                        match = 0;
                    }
                }
                else
                {
                    if (str[i] == target[0])
                        match = 1;
                    else
                        match = 0;
                }
            }
            l++;
        }

        // 更新最大值
        if (cnt > maxCnt || (cnt == maxCnt && match > edgeLen))
        {
            maxCnt = cnt;
            edgeLen = match;
        }
    }

    return {maxCnt, edgeLen};
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;

    // s 最大 CDNL 数量和后缀长度
    auto [s_cnt, s_suf] = getMaxCntAndEdge(s, m, false);
    // t 最大 CDNL 数量和前缀长度
    auto [t_cnt, t_pre] = getMaxCntAndEdge(t, k, true);

    int cross = (s_suf + t_pre >= 4) ? 1 : 0;
    int ans = s_cnt + t_cnt + cross;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
