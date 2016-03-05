#include <iostream>
#include <vector>

using namespace std;

template <typename Iter>
void max_to_end(vector <long int> &mas, Iter first, Iter last) {
    long int maximum;
    maximum = *first;
    Iter maxi = first;
    for (auto it = first; it != last; ++it) {
        if (*it > maximum) {
            maximum = *it;
            maxi = it;
        }
    }
    swap(*(--(last--)), *maxi);
}

int main() {
    int n;
    cin >> n;
    vector <long int> mas(n);
    if (n != 0) {
        for (size_t i = 0; i < n; i++) {
            cin >> mas[i];
        }
        max_to_end(mas, mas.begin(), mas.end());
        for (auto it = mas.begin(); it != mas.end(); ++it) {
            cout << *it << " ";
        }
    }
    return 0;
}
