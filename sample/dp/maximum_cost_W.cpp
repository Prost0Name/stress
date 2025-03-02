// Рюкзак максимальной стоимости

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

const int INF = INT_MAX, WMAX = 10001;


int main() {
    io();
    int n, W;
    cin >> n >> W;
    vector<int> w(n), c(n);
    cin >> w >> c;

    vector dp(n + 1, vector<int>(WMAX, 0));
    for (int i = 1; i < WMAX; ++i) {
        dp[0][i] = -INF;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < WMAX; ++j) {
            if (j >= w[i]) {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + c[i]);
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    int j = 0;
    for (int i = 0; i <= W; ++i) {
        if (dp[n][i] > dp[n][j]) {
            j = i;
        }
    }

    vector<int> ans, res;
    int i = n - 1;
    while (j != 0) {
        if (j >= w[i] && dp[i + 1][j] == dp[i][j - w[i]] + c[i]) {
            j -= w[i];
            ans.push_back(i + 1);
        } else {
        }
        --i;
    }
    cout << (int) ans.size() << '\n' << ans;
}