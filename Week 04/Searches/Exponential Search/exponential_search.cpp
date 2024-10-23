#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search_recursive(vector<int>& arr, int x, int left, int right)
{
	if (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == x)
		{
			return mid;
		}

		else if (arr[mid] > x)
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

int exponentialSearch(vector<int>& arr, int x)
{
	int N = arr.size();
	if (arr[0] == x)
	{
		return 0;
	}

	int i = 1;
	while (i < N && arr[i] <= x)
	{
		i = i * 2;
	}

	return binary_search_recursive(arr, x, i / 2, min(i, N - 1));
}

int main()
{

	vector<int> arr = { 1, 2, 3, 3, 3, 3, 3, 4, 5 };

	//pos is 0 to n,
	//-1 if not found
	cout << exponentialSearch(arr, 1) << " " << exponentialSearch(arr, 6) << endl;

	cout << exponentialSearch(arr, 3);
}