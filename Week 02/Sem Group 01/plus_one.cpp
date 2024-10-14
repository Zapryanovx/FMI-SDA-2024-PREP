#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		std::vector<int> res(digits.size());

		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			int sum = digits[i] + carry;
			if (sum == 10)
			{
				digits[i] = 0;
				carry = 1;
			}

			else
			{
				digits[i] = sum;
				carry = 0;
			}

			res[i] = digits[i];
		}

		if (res[0] == 0)
		{
			res.insert(res.begin(), 1);
		}

		return res;
	}
};