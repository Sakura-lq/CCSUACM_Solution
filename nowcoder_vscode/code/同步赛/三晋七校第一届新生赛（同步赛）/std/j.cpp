#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> q;
    vector<int> vis(n + 1, 0x3f3f3f3f);
    for (int i = 1; i <= m; i++) {
        q.push(a[i]);
        vis[a[i]] = 0;
    }
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (vis[v] > vis[u] + 1) {
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
    }
    q.push(s);
    vector<int> vis1(n + 1, 0x3f3f3f3f);
    vis1[s] = 0;
    if (vis[s] == 0) {
        std::cout << -1 << '\n';
        return;
    }
    while (q.size()) {
        auto u = q.front();
        q.pop();
        if (g[u].size() == 1 && vis1[u] < vis[u]) {
            cout << vis1[u] << '\n';
            return;
        }
        for (auto v : g[u]) {
            if (vis1[v] > vis1[u] + 1 && vis1[u] + 1 < vis[v]) {
                vis1[v] = vis1[u] + 1;
                q.push(v);
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    solve();
}
