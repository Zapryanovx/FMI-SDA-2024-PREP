#include <iostream>
#include <vector>

int main()
{
	int n;
	std::cin >> n;
	
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}

	for (int i = 1; i < n; i++)
	{
		int key = nums[i];
		int j = i - 1;
		
		while (j >= 0 && nums[j] > key)
		{
			nums[j + 1] = nums[j];
			j--;
		}

		nums[j + 1] = key;
	}


	for (int i = 0; i < n; i++)
	{
		std::cout << nums[i] << " ";
	}

	return 0;
}