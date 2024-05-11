//
//  main.cpp
//  2024.05.11.5
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

bool sortByFirst(const Pair &a, const Pair &b) {
    return a.first < b.first;
}

int maxChainLen(struct Pair arr[], int n) {
    sort(arr, arr + n, sortByFirst);
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i].first > arr[j].second && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
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
