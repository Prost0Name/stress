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

struct MinQueue {
    deque<pair<ll, ll>> d;

    void add(ll i, ll x) {
        while (!d.empty() && d.back().second >= x) {
            d.pop_back();
        }
        d.emplace_back(i, x);
    }

    void pop(ll i) {
        if (!d.empty() && d.front().first == i) {
            d.pop_front();
        }
    }

    ll get() {
        return d.front().second;
    }
};