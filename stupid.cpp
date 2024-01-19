#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// region
template<typename T>
istream &operator>>(istream &is, vector<T> &vec);

template<typename T>
ostream &operator<<(ostream &os, vector<T> &vec);

inline void io() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
}
// endregion

int main() {
    io();
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i * i <= n; ++i) {
        if (n % i == 0) {
            ++cnt;
        }
    }
    cout << cnt;
}

// region
template<typename T>
ostream &operator<<(ostream &os, vector<T> &a) {
    for (auto &x : a) {
        os << x << " ";
    }
    os << "\n";
    return os;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &a) {
    for (auto &i : a)
        is >> i;
    return is;
}
// endregion