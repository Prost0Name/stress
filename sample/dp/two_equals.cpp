// Гирьки: кучки одного размера

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

const int W = 1e4 + 1;

int main() {
    io();
    int n;
    cin >> n;
    vector<int> a(n);

    int sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }

    if (sm % 2 || n % 2) {
        cout << -1;
        return 0;
    }
    sm /= 2;

    vector dp(n + 1, vector<vector<int>> (n / 2 + 1, vector<int> (W)));

    dp[0][0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int c = 1; c <= n / 2; ++c) {
            for (int w = 0; w < W; ++w) {
                dp[i + 1][c][w] = dp[i][c][w];
                if (w >= a[i] && dp[i][c - 1][w - a[i]]) {
                    dp[i + 1][c][w] = 1;
                }
            }
        }
    }

    int i = n - 1, c = n / 2, w = sm;
    if (dp[n][c][w] == 0) {
        cout << -1;
        return 0;
    }
    vector<int> ans(n);
    while (c > 0 && i > 0 && w > 0) {
        if (w >= a[i] && dp[i][c - 1][w - a[i]]) {
            --c;
            w -= a[i];
            ans[i] = 1;
        }
        --i;
    }
    vector<int> res1, res2;
    for (i = 0; i < n; ++i) {
        if (ans[i]) {
            res1.push_back(i + 1);
        } else {
            res2.push_back(i + 1);
        }
    }
    cout << res1 << res2;
}