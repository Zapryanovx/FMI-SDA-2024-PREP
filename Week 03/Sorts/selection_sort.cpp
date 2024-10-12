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
		int minIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (nums[j] < nums[minIdx])
			{
				minIdx = j;
			}
		}

		if (minIdx != i)
		{
			std::swap(nums[minIdx], nums[i]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << nums[i] << " ";
	}

}