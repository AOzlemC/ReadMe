//
//  main.cpp
//  2024.05.11.7
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, int color, vector<int>& colors, vector<vector<int>>& graph, int N) {
    for (int i = 0; i < N; ++i) {
        if (graph[node][i] && colors[i] == color)
            return false;
    }
    return true;
}

bool graphColoringUtil(int node, int M, vector<int>& colors, vector<vector<int>>& graph, int N) {
    if (node == N)
        return true;

    for (int color = 1; color <= M; ++color) {
        if (isSafe(node, color, colors, graph, N)) {
            colors[node] = color;
            if (graphColoringUtil(node + 1, M, colors, graph, N))
                return true;
            colors[node] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int M, int N) {
    vector<int> colors(N, 0);
    if (graphColoringUtil(0, M, colors, graph, N))
        return true;
    return false;
}

int main() {
    int N1 = 4, M1 = 3;
    vector<vector<int>> graph1 = {{0, 1, 0, 1},
                                   {1, 0, 1, 0},
                                   {0, 1, 0, 1},
                                   {1, 0, 1, 0}};
    cout << graphColoring(graph1, M1, N1) << endl; // Output: 1

    int N2 = 3, M2 = 2;
    vector<vector<int>> graph2 = {{0, 1, 1},
                                   {1, 0, 1},
                                   {1, 1, 0}};
    cout << graphColoring(graph2, M2, N2) << endl; // Output: 0

    return 0;
}
