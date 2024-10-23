#include <iostream>
#include <vector>
using namespace std;

int binary_search_leftmost(vector<int>& arr, int x)
{
	int left = 0;
	int right = arr.size() - 1;

	int index = arr.size() - 1;

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
	
	//pos is index 0 to n
	//n if not found
	cout << binary_search_leftmost(arr, 1) << " " << binary_search_leftmost(arr, 6) << endl;

	//index of most left 3
	cout << binary_search_leftmost(arr, 3);
}