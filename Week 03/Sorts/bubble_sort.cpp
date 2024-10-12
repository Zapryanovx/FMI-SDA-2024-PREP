#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;

	std::vector<int> nums(n);
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cin >> nums[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				std::swap(nums[j], nums[j + 1]);
			}
		}
	}

	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}

	return 0;
}