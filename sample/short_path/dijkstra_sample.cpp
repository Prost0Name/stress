#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &i : vec)
        is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
    for (auto &x : vec)
        os << x << " ";
    return (os << "\n");
}

inline void io() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
}

int start, finish, m, n;
vector<vector<pair<int, int>>> g;
vector<int> dist, p;
vector<char> vis;
const int INF = 1e9;

void dijkstra() {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    q.emplace(0, start);

    while (!q.empty()) {
        auto [cur_d, v] = q.top();
        q.pop();

        if (cur_d > dist[v]) {
            continue;
        }

        for (auto &[u, w] : g[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                p[u] = v;
                q.emplace(dist[u], u);
            }
        }
    }
}

int main() {
    io();
    cin >> n >> m >> start >> finish;
    --start, --finish;

    dist.resize(n, INF);
    g.resize(n);
    vis.resize(n, 0);
    p.resize(n);

    for (int i = 0; i < m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        g[--v].emplace_back(--u, w);
        g[u].emplace_back(v, w);
    }

    dijkstra();
    if (dist[finish] == INF) {
        cout << -1;
        return 0;
    }

    cout << dist[finish] << '\n';

    vector<int> ans;

    for (int i = finish; i != start; i = p[i]) {
        ans.push_back(i + 1);
    }

    ans.push_back(start + 1);
    cout << ans.size() << '\n';
    for (int i = (int) ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << ' ';
    }
}