// Количество простых путей, проходящих через это ребро.

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

vector<vector<ll>> g;
vector<ll> sz, cmp, cnt;
vector<pair<ll, ll>> edge;
ll col = 0;

void dfs(ll &v) {
    sz[v] = 1;
    cmp[v] = col;
    ++cnt[col];

    for (auto &u : g[v]) {
        if (cmp[u] == -1) {
            dfs(u);
            sz[v] += sz[u];
        }
    }
}

int main() {
    io();
    ll n, m;
    cin >> n >> m;

    sz.resize(n);
    g.resize(n);
    cmp.resize(n, -1);
    cnt.resize(n);
    edge.resize(m);

    for (ll i = 0; i < m; ++i) {
        ll v, u;
        cin >> v >> u;
        g[--v].push_back(--u);
        g[u].push_back(v);
        edge[i] = {v, u};
    }

    for (ll i = 0; i < n; ++i) {
        if (cmp[i] == -1) {
            dfs(i);
            ++col;
        }
    }

    ll q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        auto &[v, u] = edge[--k];
        ll ans = min(sz[v], sz[u]) * (cnt[cmp[v]] - min(sz[v], sz[u]));
        cout << ans << '\n';
    }
}

//Входные данные
//3 2
//1 2
//2 3
//2
//1
//2
//Выходные данные
//2
//2