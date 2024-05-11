//
//  main.cpp
//  2024.05.11.1
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortByEnd(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

int maxMeetings(vector<int>& start, vector<int>& end, int N) {
    vector<pair<int, int>> meetings;
    for (int i = 0; i < N; ++i) {
        meetings.push_back(make_pair(start[i], end[i]));
    }
    
    sort(meetings.begin(), meetings.end(), sortByEnd);

    int count = 0;
    int prevEnd = 0;

    
    for (auto meeting : meetings) {
        if (meeting.first >= prevEnd) {
            count++;
            prevEnd = meeting.second;
        }
    }

    return count;
}

int main() {
    vector<int> start1 = {1, 3, 0, 5, 8, 5};
    vector<int> end1 = {2, 4, 6, 7, 9, 9};
    int N1 = 6;
    cout << maxMeetings(start1, end1, N1) << endl;

    vector<int> start2 = {10, 12, 20};
    vector<int> end2 = {20, 25, 30};
    int N2 = 3;
    cout << maxMeetings(start2, end2, N2) << endl;

    return 0;
}
