#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

void mergeSort(vector<int> &a, size_t left, size_t right, int &inversion)
{
    if (right - left < 2)
        return;
    if (right - left == 2)
    {
        if (a[left] > a[left + 1])
            swap(a[left], a[left + 1]);
        return;
    }
    mergeSort(a, left, left + (right - left) / 2, inversion);
    mergeSort(a, left + (right - left) / 2, right, inversion);
    vector<int> b;
    size_t b1 = left, e = left + (right - left) / 2, b2 = e;
    while (b.size() < right - left)
    {
        if (b1 >= e || (b2 < right && a[b2] <= a[b1]))
        {
            b.push_back(a[b2]);
            ++b2;
        }
        else
        {
            b.push_back(a[b1]);
            ++b1;
        }
    }
    for (size_t i = left; i < right; ++i)
        a[i] = b[i - left];
}

int main() {
    int n,k,inversion=0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i){
        cin >> k;
        v.push_back(k);
    }
    mergeSort(v, 0, v.size(), inversion);
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
}
