#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::vector<std::pair<int, int>> data(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			data[i].first = nums[i];
			data[i].second = i;
		}
		
		std::sort(data.begin(), data.end());

		std::vector<int>res;
		int left = 0;
		int right = nums.size() - 1;

		while (left != right)
		{
			int sum = data[left].first + data[right].first;
			if (sum == target)
			{
				res.push_back(data[left].second);
				res.push_back(data[right].second);
				return res;
			}

			else if (sum > target)
			{
				right--;
			}

			else if (sum < target)
			{
				left++;
			}
		}

		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
};