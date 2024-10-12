#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			swap(arr[j], arr[i]);
			i++;
		}
	}

	swap(arr[i], arr[high]);
	return i;
}

void quick_sort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

int main()
{
	int n; 
	std::cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}

	quick_sort(nums, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		std::cout << nums[i] << " ";
	}


	return 0;
}
