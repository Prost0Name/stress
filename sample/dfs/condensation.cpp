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

vector<vector<ll>> g, gr;
vector<ll> order, cmp;
vector<char> used;
ll cnt_cmp = 0;

void dfs(const ll &v) {
    used[v] = 1;
    for (auto u : g[v]) {
        if (used[u] == 0) {
            dfs(u);
        }
    }
    order.push_back(v);
}

void dfs2(const ll &v) {
    cmp[v] = cnt_cmp;
    for (auto &u : gr[v]) {
        if (cmp[u] == 0) {
            dfs2(u);
        }
    }
}


int main() {
    io();
    ll n, m;
    cin >> n >> m;

    g.resize(n);
    gr.resize(n);
    used.resize(n, 0);
    cmp.resize(n);

    for (int i = 0; i < m; ++i) {
        ll v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        gr[u].push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());
    int ans = 0;
    for (auto &v : order) {
        if (cmp[v] == 0) {
            ++ans;
            ++cnt_cmp;
            dfs2(v);
        }
    }

    set<pair<int, int>> st;

    for (int v = 0; v < n; ++v) {
        for (auto &u : g[v]) {
            if (cmp[v] != cmp[u]) {
                st.insert(make_pair(cmp[v], cmp[u]));
            }
        }
    }

    cout << (int) st.size();
}