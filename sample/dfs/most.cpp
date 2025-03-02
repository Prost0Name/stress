//Мостом называется ребро, при удалении которого связный неориентированный граф становится несвязным.

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

vector<char> used;
vector<int> h, uph;
vector<vector<pair<int, int>>> g;
set<int> most;

void dfs(int v, int p) {
    used[v] = 1;
    uph[v] = h[v];
    for (auto &[to, i] : g[v]) {
        if (to == p) {
            continue;
        } else if (used[to] == 1) {
            uph[v] = min(uph[v], h[to]);
        } else {
            h[to] = h[v] + 1;
            dfs(to, v);
            uph[v] = min(uph[to], uph[v]);
            if (uph[to] > h[v]) {
                most.insert(i);
            }
        }
    }
}

int main() {
    io();
    int n, m;
    cin >> n >> m;

    g.resize(n);
    used.resize(n, 0);
    h.resize(n);
    uph.resize(n);

    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        g[--v].emplace_back(--u, i + 1);
        g[u].emplace_back(v, i + 1);
    }

    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs(i, -1);
        }
    }
    cout << (int) most.size() << '\n';
    for (auto &x : most) {
        cout << x << ' ';
    }
}