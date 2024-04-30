#include <iostream>
#include <vector>

using namespace std;

int main() {
    int number_elements;
    cin >> number_elements;

    vector<int> celie_chisla(number_elements);
    for (int i = 0; i < number_elements; ++i) {
        cin >> celie_chisla[i];
    }

    int opornii_elem;
    cin >> opornii_elem;

    int counter = 0;
    for (int i : celie_chisla) {
        if (i < opornii_elem) {
            counter++;
        }
    }

    cout << counter << endl;
    cout << number_elements - counter << endl;

    return 0;
}
