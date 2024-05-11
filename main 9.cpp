//
//  main.cpp
//  2024.05.11.9
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int rows, cols;
vector<vector<bool>> visited;

bool isValid(int x, int y) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

void findWords(vector<vector<char>>& board, int x, int y, string word, unordered_set<string>& words, vector<string>& result, vector<vector<bool>>& visited) {
    if (!isValid(x, y) || visited[x][y])
        return;

    word += board[x][y];
    visited[x][y] = true;

    if (words.find(word) != words.end())
        result.push_back(word);

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0)
                continue;
            int newX = x + dx;
            int newY = y + dy;
            if (isValid(newX, newY)) {
                findWords(board, newX, newY, word, words, result, visited);
            }
        }
    }

    visited[x][y] = false;
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    rows = board.size();
    cols = board[0].size();

    unordered_set<string> words(dictionary.begin(), dictionary.end());
    vector<string> result;

    visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            string word = "";
            findWords(board, i, j, word, words, result, visited);
        }
    }

    return result;
}

int main() {
    vector<vector<char>> board1 = {{'C', 'A', 'P'}, {'A', 'N', 'D'}, {'T', 'I', 'E'}};
    vector<string> dictionary1 = {"CAT"};
    vector<string> result1 = wordBoggle(board1, dictionary1);
    for (const string& word : result1)
        cout << word << " ";
    cout << endl; // Output: CAT

    vector<vector<char>> board2 = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};
    vector<string> dictionary2 = {"GEEKS", "FOR", "QUIZ", "GO"};
    vector<string> result2 = wordBoggle(board2, dictionary2);
    for (const string& word : result2)
        cout << word << " ";
    cout << endl; // Output: GEEKS QUIZ

    return 0;
}
