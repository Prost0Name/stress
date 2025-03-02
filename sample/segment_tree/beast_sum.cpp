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

struct SegTree {
    struct Node {
        ll seg, pref, suf, sum;
    };
    vector<Node> tree;
    int size{};

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size - 1);
    }

    static Node combine(const Node &a, const Node &b) {
        return {
            max(a.seg, max(b.seg, a.suf + b.pref)),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        };
    }

    static Node one_element(int &x) {
        return {
            max(x, 0),
            max(x, 0),
            max(x, 0),
            x
        };
    }

    void add(int v, int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = one_element(v);
            return;
        }
        int m = lx + (rx - lx) / 2;
        if (i < m) {
            add(v, i, 2 * x + 1, lx, m);
        } else {
            add(v, i, 2 * x + 2, m, rx);
        }
        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void add(int v, int i) {
        add(v, i, 0, 0, size);
    }

    Node get(int l, int r, int x, int lx, int rx) {
        if (r <= lx || rx <= l) {
            return {0, 0, 0, 0};
        }
        if (l <= lx && rx <= r) {
            return tree[x];
        }
        int m = lx + (rx - lx) / 2;
        return combine(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
    }

    ll get(int l, int r) {
        return get(l, r, 0, 0, size).seg;
    }
};

int main() {
    io();
    int n, m;
    cin >> n >> m;

    SegTree st;
    st.init(n);

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        st.add(v, i);
    }

    while (m--) {
        string q;
        cin >> q;
        if (q == "change") {
            int i, v;
            cin >> i >> v;
            st.add(v, i - 1);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.get(l - 1, r) << '\n';
        }
    }
}
