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

int main() {
    io();
    int n, w;
    cin >> n >> w;

    bitset<6250000> bt;
    bt[0] = true;

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        bt |= bt << c;
    }

    cout << (bt[w] ? "YES" : "NO");
}