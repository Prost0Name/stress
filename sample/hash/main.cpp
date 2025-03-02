#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

template<typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &i : vec) is >> i;
    return is;
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
    for (auto &x : vec) os << x << " ";
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

struct myhash {
    int n;
    const int p = 237, mod = 1e9 + 21;
    vector<int> hash, pw;

    int sum(int a, int b) {
        if (a + b >= mod) {
            return a + b - mod;
        } else {
            return a + b;
        }
    }
    int sub(int a, int b) {
        if (a - b < 0) {
            return a - b + mod;
        } else {
            return a - b;
        }
    }
    int mul(int a, int b) {
        return 1ll * a * b % mod;
    }

    int get(int l, int r) {
        return sub(hash[r], mul(hash[l], pw[r - l]));
    }

    myhash(string s) {
        n = (int) s.size();
        hash.resize(n + 1);
        pw.resize(n + 1);
        pw[0] = 1;
        for (int i = 0; i < n; ++i) {
            pw[i + 1] = mul(pw[i], p);
        }
        for (int i = 0; i < n; ++i) {
            hash[i + 1] = sum(mul(hash[i], p), s[i] % mod);
        }
    }
};

int main() {
    io();
    string s;
    int q;
    cin >> s >> q;

    myhash hs(s);

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (hs.get(--l1, r1) == hs.get(--l2, r2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
