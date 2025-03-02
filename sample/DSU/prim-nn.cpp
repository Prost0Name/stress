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

const int MAXN = 5000, INF = INT_MAX;
vector<pair<double, double>> g(MAXN);
vector<double> beast_edge(MAXN), min_edge(MAXN, INF);
vector<char> used(MAXN, 0);
double ans = 0;
int n;

double W(const pair<double, double> &x, const pair<double, double> &y) {
    return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}

void prim() {
    for (int i = 0; i < n; ++i) {
        int v = -1;

        for (int u = 0; u < n; ++u) {
            if (used[u] == 0 && (v == -1 || min_edge[v] > min_edge[u])) {
                v = u;
            }
        }

        used[v] = 1;

        if (v != 0) {
            ans += beast_edge[v];
        }

        for (int u = 0; u < n; ++u) {
            if (u == v) {
                continue;
            }
            double w = W(g[v], g[u]);
            if (w < min_edge[u]) {
                min_edge[u] = w;
                beast_edge[u] = w;
            }
        }
    }
}


int main() {
    io();
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> g[i].first >> g[i].second;
    }

    prim();

    cout << fixed << setprecision(15) << ans;
}