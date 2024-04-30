﻿#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> calculate_z_function(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    vector<int> z_function = calculate_z_function(s);
    for (int i = 0; i < z_function.size(); ++i) {
        cout << z_function[i] << " ";
    }
    cout << endl;
    return 0;
}
