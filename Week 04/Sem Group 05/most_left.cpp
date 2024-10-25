#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> nums(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	int x;
	cin >> x;

	sort(nums.begin(), nums.end());

	int left = 0;
	int right = n - 1;

	int mostLeft = -1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == x)
		{
			mostLeft = mid;
			right = mid - 1;
		}

		else if (nums[mid] > x)
		{
			right = mid - 1;
		}

		else
		{
			left = mid + 1;
		}

	}

	cout << mostLeft;

	return 0;
}