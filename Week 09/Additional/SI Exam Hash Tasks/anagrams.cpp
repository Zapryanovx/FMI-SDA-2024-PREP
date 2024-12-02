// https://www.hackerrank.com/contests/5-2023-2024/challenges/challenge-4497/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int f, s;
        cin >> f >> s;

        unordered_map<string, int> s1;
        unordered_map<string, int> s2;
        for (int j = 0; j < f; j++)
        {
            string word;
            cin >> word;

            s1[word]++;
        }

        for (int k = 0; k < s; k++)
        {
            string word;
            cin >> word;

            s2[word]++;
        }

        bool isValid = true;
        for (auto& w : s2)
        {
            if (w.second > s1[w.first])
            {
                isValid = false;
                break;
            }
        }

        cout << (isValid ? "Yes" : "No") << endl;
    }
    return 0;
}