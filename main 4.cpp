//
//  main.cpp
//  2024.05.11.4
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first, second;
};

bool sortBySecond(const Pair &a, const Pair &b) {
    return a.second < b.second;
}

int maxChainLen(struct Pair arr[], int n) {
    sort(arr, arr + n, sortBySecond);
    int count = 1, end = arr[0].second;
    for (int i = 1; i < n; ++i) {
        if (arr[i].first > end) {
            count++;
            end = arr[i].second;
        }
    }
    return count;
}

int main() {
    int N1 = 5;
    Pair P1[] = {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}};
    cout << maxChainLen(P1, N1) << endl; // Output: 3

    int N2 = 2;
    Pair P2[] = {{5, 10}, {1, 11}};
    cout << maxChainLen(P2, N2) << endl; // Output: 1

    return 0;
}
