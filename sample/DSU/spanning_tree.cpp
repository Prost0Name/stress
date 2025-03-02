// Остовное дерево

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

struct Node {
    int v, u, w;
};

vector<Node> g;
vector<int> sz, a;

int get(int v) {
    if (v == a[v]) {
        return v;
    }
    return a[v] = get(a[v]);
}

void un(Node &x) {
    int v = get(x.v);
    int u = get(x.u);
    if (sz[v] > sz[u]) {
        swap(v, u);
    }
    a[v] = u;
    sz[u] += sz[v];
}

int main() {
    io();
    int n, m;
    cin >> n >> m;

    g.resize(m);
    sz.resize(n, 1);
    a.resize(m);
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        cin >> g[i].v >> g[i].u >> g[i].w;
        --g[i].v, --g[i].u;
    }

    sort(g.begin(), g.end(), [&](const Node &x, const Node &y) {
        return x.w < y.w;
    });

    int ans = 0;

    for (auto &x : g) {
        if (get(x.v) != get(x.u)) {
            un(x);
            ans += x.w;
        }
    }
    cout << ans;
}