#include "bits/stdc++.h"

using namespace std;

vector<string> readfile(string filename) {
    ifstream file(filename);
    vector<string> result;
    string word;
    while (file >> word) {
        result.push_back(word);
    }
    return result;
}

string red(const string &text) {
    return "\033[31m" + text + "\033[0m";
}

string green(const string &text) {
    return "\033[32m" + text + "\033[0m";
}


signed main() {
    for (int test = 1; test <= 1000000; ++test) {
        system("./gen > input.txt");
        system("./main");
        system("./stupid");

        if (readfile("ans.txt") != readfile("output.txt")) {
            cout << red("WA") << endl;
            break;
        } else {
            cout << green(to_string(test) + " OK") << endl;
        }
    }
}