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

struct GcdQueue {
    stack<pair<ll, ll>> head, tail;

    void push(ll &x) {
        if (head.empty()) {
            head.emplace(x, x);
        } else {
            head.emplace(x, gcd(x, head.top().second));
        }
    }

    void move() {
        while (!head.empty()) {
            ll x = head.top().first;
            if (tail.empty()) {
                tail.emplace(x, x);
            } else {
                tail.emplace(x, gcd(x, tail.top().second));
            }
            head.pop();
        }
    }

    void pop() {
        if (tail.empty()) {
            move();
        }
        tail.pop();
    }

    ll get() {
        if (!tail.empty() && !head.empty()) {
            return gcd(head.top().second, tail.top().second);
        }
        if (tail.empty() && !head.empty()) {
            return head.top().second;
        }
        if (head.empty() && !tail.empty()) {
            return tail.top().second;
        }
        return 0;
    }
};

int main() {
    io();
    ll n, k;
    cin >> n >> k;

    GcdQueue q;
    vector<ll> a(n);
    cin >> a;

    ll test = 0;
    ll ans = 0;

    for (ll i = 0; i < k; ++i) {
        q.push(a[i]);
        test = gcd(test, a[i]);
    }
    ans = max(ans, q.get());
    for (ll i = k; i < n; ++i) {
        q.pop();
        q.push(a[i]);
        ans = max(ans, q.get());
    }
    cout << ans;
}

// НОД
//Входные данные
//10 4
//2 3 4 8 12 6 12 18 4 3
//Выходные данные
//6