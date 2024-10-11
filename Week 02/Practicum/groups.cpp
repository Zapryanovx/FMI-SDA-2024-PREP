#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& groupSizes)
    {
        std::vector<int> groups[501]{};
        std::vector<std::vector<int>> result;

        size_t size = groupSizes.size();
        for (int i = 0; i < size; i++)
        {
            std::vector<int>& group = groups[groupSizes[i]];
            group.push_back(i);

            if (group.size() == groupSizes[i])
            {
                result.push_back(group);
                group.clear();
            }
        }

        return result;
    }
};
