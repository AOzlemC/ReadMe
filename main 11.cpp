//
//  main.cpp
//  2024.05.11.11
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(int A[], int N, int M, int mid) {
    int students = 1;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i] > mid)
            return false;
        if (sum + A[i] > mid) {
            students++;
            sum = A[i];
        } else {
            sum += A[i];
        }
    }
    return students <= M;
}

int findPages(int A[], int N, int M) {
    if (N < M)
        return -1;

    int sum = 0;
    for (int i = 0; i < N; ++i)
        sum += A[i];

    int low = 0, high = sum, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isValid(A, N, M, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int A1[] = {12, 34, 67, 90};
    int N1 = 4, M1 = 2;
    cout << findPages(A1, N1, M1) << endl; // Output: 113

    int A2[] = {15, 17, 20};
    int N2 = 3, M2 = 2;
    cout << findPages(A2, N2, M2) << endl; // Output: 32

    return 0;
}
