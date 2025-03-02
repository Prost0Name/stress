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
    int n, s;
    cin >> n >> s;
    vector<ll> w(n), c(n);

    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> c[i];
    }

    vector dp(n + 1, vector<ll> (1e4 + 1));

    for (int i = 1; i < 1e4 + 1; ++i) {
        dp[0][i] = INT_MAX;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 1e4 + 1; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (j >= c[i]) {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - c[i]] + w[i]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 1e4 + 1; ++i) {
        if (dp[n][i] <= s) {
            ans = i;
        }
    }

    cout << ans << '\n';

    vector<int> ans_list;
    int i = n - 1, j = ans;
    while (j != 0) {
        if (j >= c[i] && dp[i + 1][j] == dp[i][j - c[i]] + w[i]) {
            j -= (int) c[i];
            ans_list.push_back(i + 1);
        }
        --i;
    }
    cout << (int) ans_list.size() << '\n' << ans_list;
}