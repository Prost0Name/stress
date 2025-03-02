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

vector<int> a;

struct DequeMin {
    deque<pair<int, int>> d;

    void add(int i, int x) {
        while (!d.empty() && d.back().second > x) {
            d.pop_back();
        }
        d.emplace_back(i, x);
    }

    void pop(int i) {
        if (!d.empty() && d.front().first == i) {
            d.pop_front();
        }
    }

    int get() {
        return d.front().second;
    }
};

struct DequeMax {
    deque<pair<int, int>> d;

    void add(int i, int x) {
        while (!d.empty() && d.back().second < x) {
            d.pop_back();
        }
        d.emplace_back(i, x);
    }

    void pop(int i) {
        if (!d.empty() && d.front().first == i) {
            d.pop_front();
        }
    }

    int get() {
        return d.front().second;
    }
};

int main() {
    io();
    int n;;
    cin >> n;
    a.resize(n);
    cin >> a;

    int m;
    cin >> m;
    while (m--) {
        int k;
        cin >> k;
        int l = 0, r = 0;
        DequeMax mx;
        DequeMin mn;
        int la = 0, ra = 0;
        while (r < n) {
            mx.add(r, a[r]);
            mn.add(r, a[r]);
            while (l < r && mx.get() - mn.get() > k) {
                mx.pop(l);
                mn.pop(l);
                ++l;
            }
            if (ra - la < r - l) {
                ra = r;
                la = l;
            }
            ++r;
        }
        cout << la + 1 << ' ' << ra + 1 << '\n';
    }
}