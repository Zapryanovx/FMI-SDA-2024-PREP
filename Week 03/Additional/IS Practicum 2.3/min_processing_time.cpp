#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {

        sort(processorTime.begin(), processorTime.end());
        sort(tasks.rbegin(), tasks.rend());

        int max = -1;
        int taskIdx = 0;
        for (size_t i = 0; i < processorTime.size(); i++)
        {
            if (processorTime[i] + tasks[taskIdx] > max)
            {
                max = processorTime[i] + tasks[taskIdx];
            }
            taskIdx += 4;
        }

        return max;
    }
};