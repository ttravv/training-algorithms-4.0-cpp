#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> compute_prefix_function(const string& s) {
    vector<int> prefix_function(s.size(), 0);
    int border = 0;
    for (int i = 1; i < s.size(); ++i) {
        while (border > 0 && s[i] != s[border]) {
            border = prefix_function[border - 1];
        }
        if (s[i] == s[border]) {
            border++;
        }
        else {
            border = 0;
        }
        prefix_function[i] = border;
    }
    return prefix_function;
}

int main() {
    string s;
    cin >> s;
    vector<int> prefix_function = compute_prefix_function(s);
    int max_prefix_suffix_length = prefix_function.back();
    int min_length = s.size() - max_prefix_suffix_length;
    cout << min_length << endl;
    return 0;
}
