#include "testlib.h"
#include "bits/stdc++.h"

using namespace std;

random_device rd;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    rnd.setSeed(rd());

    int n = rnd.next(1, 10);
    int q = rnd.next(1, 10);
    cout << n << " " << q << "\n";
    for (int i = 0; i < n; ++i) {
        cout << rnd.next(1, 10) << " ";
    }
    cout << "\n";
    for (int i = 0; i < q; ++i) {
        cout << rnd.next(1, 100) << "\n";
    }
}