// Гирьки: три кучки

#include <bits/stdc++.h>

using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &i : vec)
        is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    for (auto x : vec)
        os << x + 1 << " ";  // Добавляем +1 для корректного индекса
    return os;
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
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;

    int W = accumulate(a.begin(), a.end(), 0);

    if (W % 3 != 0) {
        cout << -1;
        return 0;
    }

    int target = W / 3;

    vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(target + 1, vector<bool>(target + 1, false)));
    dp[0][0][0] = true;

    for (int i = 0; i < n; ++i) {
        for (int w1 = 0; w1 <= target; ++w1) {
            for (int w2 = 0; w2 <= target; ++w2) {
                if (!dp[i][w1][w2]) continue;

                dp[i + 1][w1][w2] = true;

                if (w1 + a[i] <= target)
                    dp[i + 1][w1 + a[i]][w2] = true;

                if (w2 + a[i] <= target)
                    dp[i + 1][w1][w2 + a[i]] = true;
            }
        }
    }

    if (!dp[n][target][target]) {
        cout << -1;
        return 0;
    }

    vector<int> res1, res2, res3;
    int w1 = target, w2 = target;

    for (int i = n - 1; i >= 0; --i) {
        if (w1 >= a[i] && dp[i][w1 - a[i]][w2]) {
            res1.push_back(i);
            w1 -= a[i];
        } else if (w2 >= a[i] && dp[i][w1][w2 - a[i]]) {
            res2.push_back(i);
            w2 -= a[i];
        } else {
            res3.push_back(i);
        }
    }

    cout << res1.size() << " " << res1 << "\n";
    cout << res2.size() << " " << res2 << "\n";
    cout << res3.size() << " " << res3 << "\n";
}