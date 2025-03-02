#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ld = long double;

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
vector<vector<int>> g;
vector<char> vis;
int ans = 0;

void dfs(int v) {
    vis[v] = 1;
    for (auto &u : g[v]) {
        if (vis[u] == 1) {
            cout << 1;
            exit(0);
        }
        if (vis[u] == 0) {
            dfs(u);
        }
    }
    vis[v] = 2;
}

int main() {
    io();
    int n, m;
    cin >> n >> m;
    g.resize(n);
    vis.resize(n);

    while (m--) {
        int u, v;
        cin >> u >> v;
        g[--u].push_back(--v);
    }
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }
    cout << 0;
}