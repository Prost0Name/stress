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

const int INF = 3 * 1e4;

int main() {
    io();
    int n, m;
    cin >> n >> m;

    vector d(n, vector<int> (n, INF));

    for (int i = 0; i < n; ++i) {
        d[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        --v, --u;
        d[v][u] = min(d[v][u], w);
    }

    for (int i = 0; i < n; ++i) {
        for (int v = 0; v < n; ++v) {
            for (int u = 0; u < n; ++u) {
                if (d[v][i] != INF && d[i][u] != INF) {
                    d[v][u] = min(d[v][u], d[v][i] + d[i][u]);
                }
            }
        }
    }

    for (auto &x : d) {
        cout << x;
    }
}

//Примеры
//Входные данные
//6 4
//1 2 10
//2 3 10
//1 3 100
//4 5 -10
//Выходные данные
//0 10 20 30000 30000 30000
//30000 0 10 30000 30000 30000
//30000 30000 0 30000 30000 30000
//30000 30000 30000 0 -10 30000
//30000 30000 30000 30000 0 30000
//30000 30000 30000 30000 30000 0