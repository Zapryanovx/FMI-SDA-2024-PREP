#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void addBits(unsigned n, vector<int>& counter)
    {
        int i = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                counter[i]++;
            }
            i++;
            n /= 2;
        }
    }
    int singleNumber(vector<int>& nums) {

        std::vector<int> bits(32, 0);

        for (size_t i = 0; i < nums.size(); i++)
        {
            addBits(nums[i], bits);
        }

        int res = 0;
        int powerOfTwo = 1;
        for (size_t i = 0; i < 32; i++)
        {
            if (bits[i] % 3 != 0)
            {
                res += powerOfTwo;
            }

            powerOfTwo <<= 1;
        }

        return res;
    }
};