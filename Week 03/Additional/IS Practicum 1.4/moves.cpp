#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {

        std::sort(seats.begin(), seats.end());
        std::sort(students.begin(), students.end());

        int res = 0;
        for (size_t i = 0; i < students.size(); i++)
        {
            res += std::abs(students[i] - seats[i]);
        }

        return res;
    }
};