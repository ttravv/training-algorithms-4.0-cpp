#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void radix_sort(vector<string>& arr) {
    int len_arr = arr.size();
    for (int i = 0; i < arr[0].size(); ++i) {
        vector<vector<string>> buckets(10);
        cout << "**********" << endl;
        cout << "Phase " << i + 1 << endl;
        for (const string& num : arr) {
            if (num.size() > i) {
                buckets[num[num.size() - i - 1] - '0'].push_back(num);
            }
            else {
                buckets[0].push_back(num);
            }
        }
        for (int j = 0; j < 10; ++j) {
            if (buckets[j].empty()) {
                cout << "Bucket " << j << ": empty" << endl;
            }
            else {
                cout << "Bucket " << j << ": ";
                for (int k = 0; k < buckets[j].size(); ++k) {
                    cout << buckets[j][k];
                    if (k != buckets[j].size() - 1) {
                        cout << ", ";
                    }
                }
                cout << endl;
            }
        }
        arr.clear();
        for (const vector<string>& bucket : buckets) {
            arr.insert(arr.end(), bucket.begin(), bucket.end());
        }
    }
    cout << "**********" << endl;
    cout << "Sorted array:" << endl;
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << ", ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Initial array:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    radix_sort(arr);
    return 0;
}
