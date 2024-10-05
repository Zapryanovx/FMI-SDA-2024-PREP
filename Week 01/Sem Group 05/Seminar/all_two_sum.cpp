#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, k;
	std::cin >> n >> k;
	std::vector<int> nums(n);

	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}

	std::vector<std::pair<int, int>> data(n);
	for (int i = 0; i < n; i++)
	{
		data[i].first = nums[i];
		data[i].second = i;
	}

	int left = 0;
	int right = data.size() - 1;
	int count = 0;
	while (left < right)
	{
		int sum = data[left].first + data[right].first;
		if (sum == k)
		{
			int leftCount = 1;
			int rightCount = 1;

			while (left + 1 < right && nums[left] == nums[left + 1]) 
			{
				left++;
				leftCount++;
			}

			while (right - 1 > left && nums[right] == nums[right - 1])
			{
				right--;
				rightCount++;
			}

			count += (leftCount * rightCount);
			left++;
			right--;
		}

		else if (sum > k)
		{
			right--;
		}

		else if (sum < k)
		{
			left++;
		}
	}

	std::cout << count << std::endl;
}