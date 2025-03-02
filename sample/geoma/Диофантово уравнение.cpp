//Примеры
//Входные данные
//1 2 3
//Выходные данные
//1 1


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

ll gcd_ext(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = gcd_ext(b, a % b, x, y);
    x -= (a / b) * y;
    swap(x, y);
    return d;
}

int main() {
    io();
    ll a, b, c, x, y, d;
    cin >> a >> b >> c;
    d = gcd_ext(a, b, x, y);
    if (c % d == 0) {
        ll t = c / d * x, t2 = b / d;
        if (t == 0) cout << 0 << " " << c / d * y;
        if (t > 0) cout << t + t2 * (-(t / t2)) << " " << c / d * y - a / d * (-(t / t2));
        if (t < 0) cout << t + t2 * (-((t - t2 + 1) / t2)) << " " << c / d * y - a / d * ((-((t - t2 + 1) / t2)));
    } else {
        cout << "Impossible";
    }
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
