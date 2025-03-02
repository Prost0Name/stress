#include <bits/stdc++.h>

using ll = long long;
using namespace std;

inline void ayu() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
}

int32_t main() {
    ayu();
    ll n;
    cin >> n;
    vector<char> a(1e5, 1);
    int res = 1;

    for (ll i = 2; i < 1e5 && n > 1; ++i) {
        for (ll j = i * i * 1ll; j < 1e5; j += i) {
            a[j] = 0;
        }
        if (a[i] == 1) {
            a[i] = 0;
            int cnt = 1;
            while (n % i == 0) {
                n /= i;
                ++cnt;
            }
            res *= cnt;
        }
    }
    if (n > 1) {
        ++res;
    }
    cout << res;
}