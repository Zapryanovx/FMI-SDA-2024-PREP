#include <iostream>
#include <vector>
using namespace std;

int binary_search_rightmost(vector<int>& arr, int x)
{
	int left = 0;
	int right = arr.size() - 1;

	int index = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (x >= arr[mid])
		{
			left = mid + 1;
			index = mid;
		
		}

		else
		{
			right = mid - 1;
		}
	}

	return index;
}

int main()
{
	
	vector<int> arr = { 1, 2, 3, 3, 3, 3, 3, 4, 5 };
	
	//pos is 0 to n,
	//n if not found
	cout << binary_search_rightmost(arr, 1) << " " << binary_search_rightmost(arr, 6) << endl;

	//index of most right 3
	cout << binary_search_rightmost(arr, 3);
}
