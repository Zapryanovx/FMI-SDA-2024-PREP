#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {

        vector<pair<int, int>> counter;

        sort(arr.begin(), arr.end());
        int count = 1;
        for (size_t i = 1; i < arr.size(); i++)
        {
            if (arr[i] == arr[i - 1])
            {
                count++;
            }

            else
            {
                counter.push_back({ count, arr[i - 1] });
                count = 1;
            }
        }

        counter.push_back({ count, arr[arr.size() - 1] });

        sort(counter.rbegin(), counter.rend());
        int setSize = 0;
        int occurrences = 0;
        for (size_t i = 0; i < counter.size(); i++)
        {
            if (occurrences >= arr.size() / 2)
            {
                return setSize;
            }

            else
            {
                occurrences += counter[i].first;
                setSize++;
            }
        }

        return setSize;
    }
};