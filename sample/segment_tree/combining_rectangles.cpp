#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

struct ver {
    ll mn = 0, lenmin = 0, p = 0;
};

struct otr {
    ll y1, y2, type;
};

vector<ver> tree(1e6 * 4);

void push(ll v) {
    tree[v * 2].p += tree[v].p;
    tree[v * 2 + 1].p += tree[v].p;
    tree[v].p = 0;
}

void build(ll v, ll l, ll r, vector<ll> &numsY, vector<ll> &a) {
    if (l == r) {
        tree[v].mn = 0;
        tree[v].lenmin = numsY[l + 1] - numsY[l];
    } else {
        ll mid = (l + r) / 2;
        build(v * 2, l, mid, numsY, a);
        build(v * 2 + 1, mid + 1, r, numsY, a);
        tree[v].lenmin = tree[v * 2].lenmin + tree[v * 2 + 1].lenmin;
    }
}

void update(ll v, ll l, ll r, ll tl, ll tr, ll num, vector<ll> &a) {
    if (tl > tr) {
        return;
    }
    if (l == tl && r == tr) {
        tree[v].p += num;
        return;
    }
    ll mid = (l + r) / 2;
    push(v);
    update(v * 2, l, mid, tl, min(mid, tr), num, a);
    update(v * 2 + 1, mid + 1, r, max(tl, mid + 1), tr, num, a);
    tree[v].mn = min(tree[v * 2].mn + tree[v * 2].p, tree[v * 2 + 1].mn + tree[v * 2 + 1].p);
    tree[v].lenmin = 0;
    if (tree[v].mn == tree[v * 2].mn + tree[v * 2].p) {
        tree[v].lenmin += tree[v * 2].lenmin;
    }
    if (tree[v].mn == tree[v * 2 + 1].mn + tree[v * 2 + 1].p) {
        tree[v].lenmin += tree[v * 2 + 1].lenmin;
    }
}

int main() {
    io();
    ll n;
    cin >> n;

    if (n == 0)  {
        cout << 0;
        return 0;
    }
    vector<pair<ll, ll>> x, y;
    vector<ll> numsX, numsY;

    for (int i = 0; i < n; ++i) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x.emplace_back(x1, x2);
        y.emplace_back(y1, y2);
        numsX.push_back(x1);
        numsX.push_back(x2);
        numsY.push_back(y1);
        numsY.push_back(y2);
    }

    sort(numsX.begin(), numsX.end());
    numsX.erase(unique(numsX.begin(), numsX.end()), numsX.end());

    sort(numsY.begin(), numsY.end());
    numsY.erase(unique(numsY.begin(), numsY.end()), numsY.end());

    auto get = [&](ll x, vector<ll> &v) {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    };

    for (auto &[lx, rx] : x) {
        lx = (ll) get(lx, numsX);
        rx = (ll) get(rx, numsX);
    }
    for (auto &[ly, ry] : y) {
        ly = (ll) get(ly, numsY);
        ry = (ll) get(ry, numsY);
    }

    vector<vector<otr>> v(numsX.size());
    for (int i = 0; i < n; i++) {
        v[x[i].first].push_back({y[i].first, y[i].second, 1});
        v[x[i].second].push_back({y[i].first, y[i].second, -1});
    }

    ll res = 0;
    vector<ll> win(numsY.size() - 1, 0);
    build(1, 0, (ll) win.size() - 1, numsY, win);
    for (int i = 0; i < (ll)v.size() - 1; i++) {
        for (auto [y1, y2, type] : v[i]) {
            update(1, 0, (ll) win.size() - 1, y1, y2 - 1, type, win);
        }
        ll s = numsY.back() - numsY[0];
        if (tree[1].mn + tree[1].p == 0) {
            s -= tree[1].lenmin;
        }
        res += s * (numsX[i + 1] - numsX[i]);
    }
    cout << res;
}

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

//Входные данные
//2
//0 0 2 2
//1 3 2 4
//Выходные данные
//5