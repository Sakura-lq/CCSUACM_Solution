#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8; // 统一精度阈值

// 点结构：封装坐标操作
struct Point
{
    double x, y;
    Point(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator+(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator*(double k) const
    {
        return Point(x * k, y * k);
    }
    // 计算两点间欧氏距离
    double dist(const Point &p) const
    {
        double dx = x - p.x;
        double dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
};

// 计算“一人移动、一人停止”阶段的最短距离（t ∈ [L, R]）
// fixed_p：固定点（已停止的人），moving_start：移动者起点，dir：移动者单位方向向量
double calc_moving_fixed(const Point &fixed_p, const Point &moving_start,
                         const Point &dir, double L, double R)
{
    // 移动者在时间t的位置：moving_start + dir * (t)
    // 距离平方 = (fixed_p.x - (moving_start.x + dir.x * t))² + (fixed_p.y - (moving_start.y + dir.y * t))²
    // 展开为：a*t² + b*t + c，求极值点t0 = -b/(2a)
    double a = dir.x * dir.x + dir.y * dir.y;
    double b = 2 * (dir.x * (moving_start.x - fixed_p.x) + dir.y * (moving_start.y - fixed_p.y));

    double min_dist = 1e18;
    // 计算区间端点距离
    Point p_L = moving_start + dir * L;
    Point p_R = moving_start + dir * R;
    min_dist = min(min_dist, fixed_p.dist(p_L));
    min_dist = min(min_dist, fixed_p.dist(p_R));

    // 计算极值点（若a≠0且t0在[L, R]内）
    if (fabs(a) > EPS)
    {
        double t0 = -b / (2 * a);
        if (t0 >= L - EPS && t0 <= R + EPS)
        {                            // 允许微小误差，避免边界漏判
            t0 = max(L, min(t0, R)); // 确保t0在区间内
            Point p0 = moving_start + dir * t0;
            min_dist = min(min_dist, fixed_p.dist(p0));
        }
    }
    return min_dist;
}

// 计算“两人均移动”阶段的最短距离（t ∈ [0, t_min]）
double calc_both_moving(const Point &T0, const Point &dt,
                        const Point &A0, const Point &da, double t_min)
{
    // 高桥位置：T0 + dt*t，青木位置：A0 + da*t
    // 距离平方 = [(T0.x - A0.x) + (dt.x - da.x)*t]² + [(T0.y - A0.y) + (dt.y - da.y)*t]²
    // 展开为：a*t² + b*t + c，求极值点t0 = -b/(2a)
    double dx0 = T0.x - A0.x;
    double dy0 = T0.y - A0.y;
    double dx_dir = dt.x - da.x;
    double dy_dir = dt.y - da.y;

    double a = dx_dir * dx_dir + dy_dir * dy_dir;
    double b = 2 * (dx0 * dx_dir + dy0 * dy_dir);

    double min_dist = 1e18;
    // 计算区间端点距离
    Point T0_p = T0 + dt * 0;
    Point A0_p = A0 + da * 0;
    Point T_min_p = T0 + dt * t_min;
    Point A_min_p = A0 + da * t_min;
    min_dist = min(min_dist, T0_p.dist(A0_p));       // t=0
    min_dist = min(min_dist, T_min_p.dist(A_min_p)); // t=t_min

    // 计算极值点（若a≠0且t0在[0, t_min]内）
    if (fabs(a) > EPS)
    {
        double t0 = -b / (2 * a);
        if (t0 >= -EPS && t0 <= t_min + EPS)
        {
            t0 = max(0.0, min(t0, t_min));
            Point T_p = T0 + dt * t0;
            Point A_p = A0 + da * t0;
            min_dist = min(min_dist, T_p.dist(A_p));
        }
    }
    return min_dist;
}

void solve()
{
    // 读取输入：高桥(TS→TG)，青木(AS→AG)
    int tsx, tsy, tgx, tgy, asx, asy, agx, agy;
    cin >> tsx >> tsy >> tgx >> tgy >> asx >> asy >> agx >> agy;

    Point T0(tsx, tsy), T1(tgx, tgy); // 高桥起点、终点
    Point A0(asx, asy), A1(agx, agy); // 青木起点、终点

    // 1. 计算高桥的移动参数
    double t_taka = T0.dist(T1); // 移动时间（距离=时间，速度=1）
    Point delta_T = T1 - T0;
    Point dt = delta_T * (1.0 / t_taka); // 单位方向向量（每秒移动的距离）

    // 2. 计算青木的移动参数
    double t_aoki = A0.dist(A1);
    Point delta_A = A1 - A0;
    Point da = delta_A * (1.0 / t_aoki);

    // 3. 阶段分界点
    double t_min = min(t_taka, t_aoki);
    double t_max = max(t_taka, t_aoki);

    // 4. 分阶段计算最短距离
    double min_total = 1e18;

    // 阶段1：两人均移动（t ∈ [0, t_min]）
    double dist_stage1 = calc_both_moving(T0, dt, A0, da, t_min);
    min_total = min(min_total, dist_stage1);

    // 阶段2：一人移动、一人停止（t ∈ [t_min, t_max]）
    double dist_stage2;
    if (t_taka <= t_aoki + EPS)
    { // 高桥先停，青木继续移动
        // 高桥位置固定为T1，青木从A_min（t_min时的位置）移动到A1（t_max时的位置）
        Point A_min = A0 + da * t_min;
        dist_stage2 = calc_moving_fixed(T1, A_min, da, t_min, t_max);
    }
    else
    { // 青木先停，高桥继续移动
        // 青木位置固定为A1，高桥从T_min（t_min时的位置）移动到T1（t_max时的位置）
        Point T_min = T0 + dt * t_min;
        dist_stage2 = calc_moving_fixed(A1, T_min, dt, t_min, t_max);
    }
    min_total = min(min_total, dist_stage2);

    // 阶段3：两人均停止（t ≥ t_max），距离固定为T1与A1的距离
    double dist_stage3 = T1.dist(A1);
    min_total = min(min_total, dist_stage3);

    // 输出结果（保留15位小数，满足精度要求）
    printf("%.15f\n", min_total);
}

int main()
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