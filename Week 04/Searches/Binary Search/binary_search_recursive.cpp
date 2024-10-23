#include <iostream>
#include <vector>
using namespace std;

int binary_search_recursive(vector<int>& arr, int x, int left, int right)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;
		
		if (x == arr[mid])
		{
			return mid;
		}

		else if (x < arr[mid])
		{
			return binary_search_recursive(arr, x, left, mid - 1);
		}

		else
		{
			return binary_search_recursive(arr, x, mid + 1, right);
		}
	}

	return -1;
}

int main()
{
	
	vector<int> arr = { 1, 2, 3, 3, 3, 3, 3, 4, 5 };
	
	//pos is 0 to n,
	//n if not found
	cout << binary_search_recursive(arr, 1, 0, arr.size() - 1) << " " << binary_search_recursive(arr, 6, 0, arr.size() - 1) << endl;

	//index of first found 3
	cout << binary_search_recursive(arr, 3, 0, arr.size() - 1);
}
