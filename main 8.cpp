//
//  main.cpp
//  2024.05.11.8
//
//  Created by ozlem on 11.05.2024.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string s) {
    int n = s.length();
    if (n > 3 || n == 0)
        return false;
    if (n > 1 && s[0] == '0')
        return false;
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

vector<string> genIp(string S) {
    int n = S.length();
    vector<string> result;
    if (n < 4 || n > 12)
        return {"-1"};

    for (int i = 1; i < n && i < 4; ++i) {
        string first = S.substr(0, i);
        if (!isValid(first))
            continue;
        for (int j = 1; j < n - i && j < 4; ++j) {
            string second = S.substr(i, j);
            if (!isValid(second))
                continue;
            for (int k = 1; k < n - i - j && k < 4; ++k) {
                string third = S.substr(i + j, k);
                string fourth = S.substr(i + j + k);
                if (isValid(third) && isValid(fourth)) {
                    string ip = first + "." + second + "." + third + "." + fourth;
                    result.push_back(ip);
                }
            }
        }
    }

    return result.empty() ? vector<string>{"-1"} : result;
}

int main() {
    string S1 = "1111";
    vector<string> result1 = genIp(S1);
    for (const string& ip : result1)
        cout << ip << " ";
    cout << endl; // Output: 1.1.1.1

    string S2 = "55";
    vector<string> result2 = genIp(S2);
    for (const string& ip : result2)
        cout << ip << " ";
    cout << endl; // Output: -1

    return 0;
}
