#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<int>& arr, vector<int>& left_arr, vector<int>& right_arr)
{
	int index = 0, left = 0, right = 0;
	int left_size = left_arr.size();
	int right_size = right_arr.size();

	while (left < left_size && right < right_size)
	{
		if (left_arr[left] <= right_arr[right])
		{
			arr[index] = left_arr[left];
			left++;
		}

		else
		{
			arr[index] = right_arr[right];
			right++;
		}

		index++;
	}

	while (left < left_size)
	{
		arr[index] = left_arr[left];
		left++;
		index++;
	}

	while (right < right_size)
	{
		arr[index] = right_arr[right];
		right++;
		index++;
	}

}

void merge_sort(vector<int>& arr)
{
	if (arr.size() > 1)
	{
		int middle = arr.size() / 2;

		vector<int> left_arr(arr.begin(), arr.begin() + middle);
		vector<int> right_arr(arr.begin() + middle, arr.end());

		merge_sort(left_arr);
		merge_sort(right_arr);
		merge(arr, left_arr, right_arr);

	}
}

int main()
{
	int n;
	cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}

	merge_sort(nums);

	for (int i = 0; i < n; i++)
	{
		std::cout << nums[i] << " ";
	}


	return 0;
}