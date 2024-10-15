#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static bool compare(pair<int, string>& lhs, pair<int, string>& rhs)
{
    if (lhs.first == rhs.first)
    {
        return lhs.second < rhs.second;
    }
    return lhs.first > rhs.first;
}

int main() {

    int n;
    cin >> n;
    vector<pair<int, string>> students(n);

    for (size_t i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        students[i].second = name;
    }

    for (size_t i = 0; i < n; i++)
    {
        int points;
        cin >> points;
        students[i].first = points;
    }

    std::sort(students.begin(), students.end(), compare);

    for (size_t i = 0; i < n; i++)
    {
        cout << students[i].second << " " << students[i].first << endl;;
    }

    return 0;
}