//
//  main.cpp
//  2024.05.11.10
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>

using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k) {
    if (n > m)
        return kthElement(arr2, arr1, m, n, k);

    if (n == 0)
        return arr2[k - 1];

    if (k == 1)
        return min(arr1[0], arr2[0]);

    int i = min(n, k / 2);
    int j = min(m, k / 2);

    if (arr1[i - 1] < arr2[j - 1])
        return kthElement(arr1 + i, arr2, n - i, m, k - i);
    else
        return kthElement(arr1, arr2 + j, n, m - j, k - j);
}

int main() {
    int arr1[] = {2, 3, 6, 7, 9};
    int arr2[] = {1, 4, 8, 10};
    int k1 = 5;
    cout << kthElement(arr1, arr2, 5, 4, k1) << endl; // Output: 6

    int arr3[] = {100, 112, 256, 349, 770};
    int arr4[] = {72, 86, 113, 119, 265, 445, 892};
    int k2 = 7;
    cout << kthElement(arr3, arr4, 5, 7, k2) << endl; // Output: 256

    return 0;
}
