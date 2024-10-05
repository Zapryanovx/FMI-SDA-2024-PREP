#include <iostream>
#include <vector>
#include <algorithm>

//Идея:
//ще направим нов вектор от двойки от вида {стойност, индекс в оригиналния масив}
//по този начин може да се възползваме от std::sort, тъй като ще ги сортира
//спрямо първия елемент на двойката (стойността) и вече не се притесняваме, че
//ще се развали подредбата, тъй като сме запазили индекса, на който по принцип се намира
//елемента във втория елемент на двойката

//сортирането ни позволява да направим по-ефективен алгоритъм спрямо сложност по време

//след като вече сме сортирали масива, напр.:
//nums = [3, 2, 4], target = 6

//data има вида:
//data = [{2, 1}, {3, 0}, {4, 2}]
//         ^  ^
//стойност-|  |-индекс в nums

//сега може да имаме два индекса - започващи отляво и отдясно (left и right)
//left = 0
//right = size - 1

//когато направим сумата между стойностите на позиции left и right:
//1) тя е равна на target => сме намерили отговора и връщаме вектор от индексите им в nums
//2) тя е по-голяма от target => трябва да намалим сумата => ще върнем right с една позиция наляво,
//   за да отговаря на по-малка стойност
//3) тя е по-малка от taget => трябва да увеличим сумата => ще преместим left с една позиция на дясно,
//   за да отговаря на по-голяма стойност

//Спрямо горния пример:
//left = 0, right = 2
//first - стойността
//second - индексът в nums
//data[left].first + data[right].first = 6 = target
//=> връщаме вектор от data[left].second и data[right].second

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
	std::vector<std::pair<int,int>> data(nums.size());
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

	//not found
	res.push_back(-1);
	res.push_back(-1);
	return res;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::vector<int>nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);

	int target = 9;

	std::vector<int>res = twoSum(nums, target);
	for (int i = 0; i < res.size(); i++)
	{
		std::cout << res[i] << ' ';
	}


	return 0;
}