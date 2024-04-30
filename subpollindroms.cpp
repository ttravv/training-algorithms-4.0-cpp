#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_palindromic_substrings(const string& s) {
    int n = s.size();
    int count = 0;

    // Преобразование строки s для вставки специальных символов между символами
    string modified_s = "#";
    for (int i = 0; i < n; ++i) {
        modified_s += s[i];
        modified_s += "#";
    }

    // Массив для хранения длин палиндромов с центром в каждой позиции
    vector<int> lengths(modified_s.size(), 0);
    int center = 0; // Центр самого правого палиндрома
    int right = 0;  // Правая граница самого правого палиндрома

    for (int i = 1; i < modified_s.size() - 1; ++i) {
        // Определяем начальное значение длины палиндрома
        if (i < right) {
            lengths[i] = min(right - i, lengths[2 * center - i]);
        }

        // Попытка расширить палиндром в обе стороны
        while (i - lengths[i] - 1 >= 0 && i + lengths[i] + 1 < modified_s.size() &&
            modified_s[i - lengths[i] - 1] == modified_s[i + lengths[i] + 1]) {
            lengths[i] += 1;
        }

        // Если палиндром стал длиннее, обновляем центр и границы
        if (i + lengths[i] > right) {
            center = i;
            right = i + lengths[i];
        }

        // Каждый найденный палиндром прибавляется к общему количеству
        count += (lengths[i] + 1) / 2;
    }

    return count;
}

int main() {
    string s;
    cin >> s;
    cout << count_palindromic_substrings(s) << endl;
    return 0;
}
