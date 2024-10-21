#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {

        std::sort(target.begin(), target.end());
        std::sort(arr.begin(), arr.end()); 

        for (size_t i = 0; i < arr.size(); i++)
        {
           if (target[i] != arr[i])
           {
               return false;
           }
        }

        return true;
    }
};