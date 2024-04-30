#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
    vector<int> merged_arr;
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged_arr.push_back(arr1[i]);
            i++;
        }
        else {
            merged_arr.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        merged_arr.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        merged_arr.push_back(arr2[j]);
        j++;
    }
    return merged_arr;
}

vector<int> merge_sort(vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    int mid = arr.size() / 2;
    vector<int> left_half(arr.begin(), arr.begin() + mid);
    vector<int> right_half(arr.begin() + mid, arr.end());

    left_half = merge_sort(left_half);
    right_half = merge_sort(right_half);

    return merge(left_half, right_half);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> sorted_arr = merge_sort(arr);
    for (int i = 0; i < sorted_arr.size(); ++i) {
        cout << sorted_arr[i] << " ";
    }
    cout << endl;
    return 0;
}
