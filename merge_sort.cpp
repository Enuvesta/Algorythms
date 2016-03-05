#include <iostream>
#include <vector>

using namespace std;

template <typename Iter>
void Merge(Iter first1, Iter last1, Iter first2, Iter last2, Iter pos) {
    while (first1 != last1 && first2 != last2) {
        if (*first1 == *first2) {
            *pos = *first1;
            pos++;
            *pos = *first1;
            pos++;
            first1++;
            first2++;
        } else {
            if (*first1 < *first2) {
                *pos = *first1;
                pos++;
                first1++;
            } else {
                *pos = *first2;
                pos++;
                first2++;
            }
        }
    }
    while (first1 != last1) {
        *pos = *first1;
        pos++;
        first1++;
    }
    while (first2 != last2) {
        *pos = *first2;
        pos++;
        first2++;
    }


}

int main(){
    int number, number2;
    cin >> number;
    vector <long int> mas(number);
    if (number != 0) {
        for (size_t i = 0; i < number; i++) {
            cin >> mas[i];
        }
    }
    cin >> number2;
    vector <long int> mas2(number2);
    if (number2 != 0) {
        for (size_t i = 0; i < number2; i++) {
            cin >> mas2[i];
        }
    }
    vector<long int> result(number + number2);
    Merge(mas.begin(), mas.end(), mas2.begin(), mas2.end(), result.begin());
    for (auto it = result.begin(); it != result.end(); it++) {
            cout << *it << " ";
        }
    return 0;
}
