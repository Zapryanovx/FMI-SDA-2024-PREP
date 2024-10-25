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

	auto left = lower_bound(nums.begin(), nums.end(), x);
	auto right = upper_bound(nums.begin(), nums.end(), x);

	cout << distance(left, right);


	return 0;
}