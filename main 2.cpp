//
//  main.cpp
//  2024.05.11.2
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortByProfit(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return get<2>(a) > get<2>(b);
}

vector<int> JobScheduling(int N, vector<tuple<int, int, int>>& Jobs) {
    sort(Jobs.begin(), Jobs.end(), sortByProfit);
    
    int maxDeadline = 0;
    for (auto& job : Jobs) {
        maxDeadline = max(maxDeadline, get<1>(job));
    }

    vector<int> result(maxDeadline, -1);
    int count = 0;
    int profit = 0;
    

    for (auto& job : Jobs) {
        int deadline = get<1>(job);
        int jobProfit = get<2>(job);
        
        for (int i = deadline - 1; i >= 0; i--) {
            if (result[i] == -1) {
                result[i] = get<0>(job);
                count++;
                profit += jobProfit;
                break;
            }
        }
    }

    return {count, profit};
}

int main() {
    int N1 = 4;
    vector<tuple<int, int, int>> Jobs1 = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> result1 = JobScheduling(N1, Jobs1);
    cout << result1[0] << " " << result1[1] << endl;

    int N2 = 5;
    vector<tuple<int, int, int>> Jobs2 = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    vector<int> result2 = JobScheduling(N2, Jobs2);
    cout << result2[0] << " " << result2[1] << endl; 

    return 0;
}
