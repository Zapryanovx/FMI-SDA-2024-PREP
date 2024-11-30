#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int calcLongestEqualSeq(vector<int>& nums)
{
    unordered_map<int, int> prefixIndex;

    int maxLength = 0;
    int prefixSum = 0;

    prefixIndex[0] = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        // if 1s are equal to 0s, set all 0s to -1, so n*1 + n*(-1) = 0
        //where n is the count of 1s and 0s
        prefixSum += (nums[i] == 0 ? -1 : 1);

        //if two sums are equal for example
        //-2 .... -2, the sequence between them is equal to 0,
        //so size of 1s == size of 0s
        if (prefixIndex.find(prefixSum) != prefixIndex.end())
        {
            maxLength = max(maxLength, i - prefixIndex[prefixSum]);
        }

        else
        {
            prefixIndex[prefixSum] = i;
        }
    }

    return maxLength;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << calcLongestEqualSeq(nums);

    return 0;
}
