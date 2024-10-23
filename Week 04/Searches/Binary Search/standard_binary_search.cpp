#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& arr, int x)
{
	int left = 0;
	int right = arr.size() - 1;

	int index = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (x <= arr[mid])
		{
			right = mid - 1;
			index = mid;
		}

		else
		{
			left = mid + 1;
		}
	}

	return index;
}

int main()
{
	
	vector<int> arr = { 1, 2, 3, 3, 3, 3, 3, 4, 5 };
	
	//pos is 0 to n,
	//0 if not found
	cout << binary_search(arr, 1) << " " << binary_search(arr, 6) << endl;

	cout << binary_search(arr, 3);
}