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
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif
}
// endregion

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    cin >> m;
    vector<int> b(n);
    cin >> b;
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        dp[i][]
    }
}

int main() {
    io();
    int t;
    cin >> t;
    while (t--) solve();
}

// region
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
// endregion

