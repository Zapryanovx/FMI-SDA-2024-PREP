#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int goal = 0;
	std::cin >> goal;
	
	std::vector<std::pair<int, int>> nums;
	nums.push_back({ 0, 0 });
	
	int multiplier = 1;
	int points = 1;
	while (multiplier < 4)
	{
		nums.push_back({ points++, multiplier });
		

		if (points > 20)
		{
			if (multiplier != 3)
			{
				nums.push_back({ 25, multiplier });
			}

			points = 1;
			multiplier++;
		}
	}

	int count = 0;
	for (size_t i = 22; i < 43; i++)
	{
		if (nums[i].first * nums[i].second == goal)
		{
			count++;
		}
	}

	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = 22; j < 43; j++)
		{
			if (nums[i].first * nums[i].second +
				nums[j].first * nums[j].second == goal)
			{
				count++;
			}
		}
	}

	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = 0; j < nums.size(); j++)
		{
			for (size_t k = 22; k < 43; k++)
			{
				if (nums[i].first * nums[i].second +
					nums[j].first * nums[j].second +
					nums[k].first * nums[k].second == goal)
				{
					count++;
				}
			}
		}
	}

	std::cout << count;
}