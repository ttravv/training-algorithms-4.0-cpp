#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generate_permutations(vector<int>& numbers, int index) {
    if (index == numbers.size() - 1) {
        for (int i = 0; i < numbers.size(); ++i) {
            cout << numbers[i];
        }
        cout << endl;
        return;
    }

    for (int i = index; i < numbers.size(); ++i) {
        swap(numbers[i], numbers[index]);
        generate_permutations(numbers, index + 1);
        swap(numbers[i], numbers[index]); // Вернуть в исходное состояние для следующей итерации
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        numbers[i] = i + 1;
    }
    generate_permutations(numbers, 0);
    return 0;
}
