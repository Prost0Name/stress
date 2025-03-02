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

struct OrQueue {
    stack<pair<ll, ll>> head, tail;

    void push(ll &x) {
        if (head.empty()) {
            head.emplace(x, x);
        } else {
            head.emplace(x, x | head.top().second);
        }
    }

    void move() {
        while (!head.empty()) {
            ll x = head.top().first;
            if (tail.empty()) {
                tail.emplace(x, x);
            } else {
                tail.emplace(x, x | tail.top().second);
            }
            head.pop();
        }
    }

    void pop() {
        if (tail.empty() && head.empty()) {
            return;
        }
        if (tail.empty()) {
            move();
        }
        tail.pop();
    }

    ll get() {
        if (!tail.empty() && !head.empty()) {
            return head.top().second | tail.top().second;
        }
        if (tail.empty() && !head.empty()) {
            return head.top().second;
        }
        if (head.empty() && !tail.empty()) {
            return tail.top().second;
        }
        return 0;
    }

    bool empty() {
        if (!head.empty() || !tail.empty()) {
            return false;
        }
        return true;
    }
};

int main() {
    io();
    ll n, k;
    cin >> n >> k;

    OrQueue q;
    vector<ll> a(n);
    cin >> a;

    ll r = 0, ans = 0;
    for (ll l = 0; l < n; ++l) {
        r = max(r, l);
        while (r < n && q.get() < k || q.empty()) {
            q.push(a[r]);
            ++r;
        }

        if (q.get() >= k) {
            ans += n - r + 1;
        } else {
            break;
        }
        q.pop();
    }
    cout << ans;
}