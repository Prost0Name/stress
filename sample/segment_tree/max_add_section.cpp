// Максимум на подотрезках с добавлением на отрезке

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
        int val, add;
    };
    vector<Node> tree;

    int size;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.resize(2 * size - 1);
    }

    void apply(int x, int v) {
        tree[x].val += v;
        tree[x].add += v;
    }

    void push(int x) {
        apply(2 * x + 1, tree[x].add);
        apply(2 * x + 2, tree[x].add);
        tree[x].add = 0;
    }

    void upd(int v, int l, int r, int x, int lx, int rx) {
        if (r <= lx || rx <= l) {
            return;
        }
        if (l <= lx && rx <= r) {
            apply(x, v);
            return;
        }
        push(x);
        int m = lx + (rx - lx) / 2;
        upd(v, l, r, 2 * x + 1, lx, m);
        upd(v, l, r, 2 * x + 2, m, rx);
        tree[x].val = max(tree[2 * x + 1].val, tree[2 * x + 2].val);
    }

    void upd(int v, int l, int r) {
        upd(v, l, r, 0, 0, size);
    }

    int get(int l, int r, int x, int lx, int rx) {
        if (r <= lx || l >= rx) {
            return 0;
        }
        if (l <= lx && rx <= r) {
            return tree[x].val;
        }
        push(x);
        int m = lx + (rx - lx) / 2;
        return max(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
    }

    int get(int l, int r) {
        return get(l, r, 0, 0, size);
    }
};

int main() {
    io();
    int n;
    cin >> n;

    SegTree st;
    st.init(n);

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        st.upd(c, i, i + 1);
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        if (c == 'm') {
            int l, r;
            cin >> l >> r;
            cout << st.get(--l, r) << ' ';
        } else {
            int l, r, add;
            cin >> l >> r >> add;
            st.upd(add, --l, r);
        }
    }
}