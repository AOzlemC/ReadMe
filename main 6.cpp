//
//  main.cpp
//  2024.05.11.6
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrack(vector<vector<int>>& m, int row, int col, int N, string path, vector<string>& result) {
    if (row == N - 1 && col == N - 1) {
        result.push_back(path);
        return;
    }

    if (col + 1 < N && m[row][col + 1] == 1) {
        m[row][col] = 0;
        backtrack(m, row, col + 1, N, path + "R", result);
        m[row][col] = 1;
    }

    if (row + 1 < N && m[row + 1][col] == 1) {
        m[row][col] = 0;
        backtrack(m, row + 1, col, N, path + "D", result);
        m[row][col] = 1;
    }

    if (row - 1 >= 0 && m[row - 1][col] == 1) {
        m[row][col] = 0;
        backtrack(m, row - 1, col, N, path + "U", result);
        m[row][col] = 1;
    }

    if (col - 1 >= 0 && m[row][col - 1] == 1) {
        m[row][col] = 0;
        backtrack(m, row, col - 1, N, path + "L", result);
        m[row][col] = 1;
    }
}

vector<string> printPath(int N, vector<vector<int>>& m) {
    vector<string> result;
    if (m[0][0] == 0 || m[N - 1][N - 1] == 0)
        return result;

    backtrack(m, 0, 0, N, "", result);
    return result;
}

int main() {
    int N1 = 4;
    vector<vector<int>> m1 = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    vector<string> result1 = printPath(N1, m1);
    for (const string& path : result1)
        cout << path << " ";
    cout << endl;

    int N2 = 2;
    vector<vector<int>> m2 = {{1, 0},
                               {1, 0}};
    vector<string> result2 = printPath(N2, m2);
    for (const string& path : result2)
        cout << path << " ";
    cout << endl;

    return 0;
}
