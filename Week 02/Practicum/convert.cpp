#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {

        int data[200]{};
        int maxOccurrences = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxOccurrences = std::max(maxOccurrences, ++data[nums[i] - 1]);
        }

        std::vector<std::vector<int>> arrays(maxOccurrences);

        int bucket = 0;
        int i = 0;
        while (i != 200)
        {
            if (data[i]--)
            {
                arrays[bucket].push_back(i + 1);
                bucket++;
            }

            else
            {
                i++;
                bucket = 0;
            }
        }

        return arrays;
    }
};