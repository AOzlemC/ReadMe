//
//  main.cpp
//  2024.05.11.3
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortByDeadline(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<1>(a) < get<1>(b);
}

int maxProfit(vector<tuple<int, int, int>>& Jobs) {
    int N = Jobs.size();
    sort(Jobs.begin(), Jobs.end(), sortByDeadline);
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int jobDeadline = get<1>(Jobs[i - 1]);
        int jobProfit = get<2>(Jobs[i - 1]);
        int j = min(i, jobDeadline);
        int includedProfit = dp[j - 1] + jobProfit;
        int notIncludedProfit = dp[i - 1];
        dp[i] = max(includedProfit, notIncludedProfit);
    }

    return dp[N];
}

int main() {
    vector<tuple<int, int, int>> Jobs1 = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    cout << maxProfit(Jobs1) << endl;

    vector<tuple<int, int, int>> Jobs2 = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    cout << maxProfit(Jobs2) << endl;

    return 0;
}
