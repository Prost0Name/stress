#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

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

const ld pi = acos(-1);

struct Point {
    ld x, y;
    explicit Point(ld x = 0, ld y = 0) : x(x), y(y) {}
    Point(Point a, Point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    Point operator+(Point p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(Point p) const {
        return Point(x - p.x, y - p.y);
    }
    Point operator*(int n) const {
        return Point(x * n, y * n);
    }
    ld operator%(Point p) const { // ( ) скалярое  a * b * sin
        return x * p.x + y * p.y;
    }
    ld operator*(Point p) const { // [ ] вектороное a * b * cos
        return x * p.y - y * p.x;
    }
    ld len() const {
        return sqrt(x * x + y * y);
    }
};

ld dist(Point a, Point b) {
    return Point(a, b).len();
}

istream &operator>>(istream &is, Point &x) {
    is >> x.x >> x.y;
    return is;
}

ld f(auto v1, ld &ans1) {
    if (v1.x < 0) {
        ans1 += pi;
    } else if (v1.x == 0) {
        if (v1.y > 0) {
            ans1 += pi / 2;
        } else {
            ans1 -= pi / 2;
        }
    }
    return ans1;
}

signed main() {
    io();
    Point a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    auto v1 = Point(a1, a2);
    auto v2 = Point(b1, b2);

    cout << fixed << setprecision(15);
    cout << v1.len() << ' ' << v2.len() << '\n';
    cout << (v1 + v2).x << ' ' << (v1 + v2).y << '\n';
    cout << v1 % v2 << ' ' << v1 * v2 << '\n';
    auto v3 = Point(v1, v2);
    auto p = (v3.len() + v2.len() + v1.len()) / 2;
    cout << sqrt(p * (p - v1.len()) * (p - v2.len()) * (p - v3.len())) << '\n';
    ld ans1 = atan(v1.y / v1.x);
    ld ans2 = atan(v2.y / v2.x);
    cout << f(v1, ans1) << ' ' << f(v2, ans2) << '\n';
    cout << 2 * pi - acos((v1 % v2) / (v1.len() * v2.len())) << '\n';
    cout << (360 - acos((v1 % v2) / (v1.len() * v2.len())) * 180 / pi) / 360 << '\n';
}