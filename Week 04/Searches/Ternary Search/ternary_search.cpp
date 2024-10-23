#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(vector<int>& arr, int x, int left, int right)
{
	if (left <= right)
	{
		int mid1 = left + (right - left) / 3;
		int mid2 = right - (right - left) / 3;

		if (arr[mid1] == x)
		{
			return mid1;
		}

		if (arr[mid2] == x)
		{
			return mid2;
		}

		if (x < arr[mid1])
		{
			return ternarySearch(arr, x, left, mid1 - 1);
		}

		else if (x > arr[mid2])
		{
			return ternarySearch(arr, x, mid2 + 1, right);
		}

		else
		{
			return ternarySearch(arr, x, mid1 + 1, mid2 - 1);
		}
	}

	return -1; //not found
}

int main()
{

	vector<int> arr = { 1, 2, 3, 3, 3, 3, 3, 4, 5 };

	//pos is 0 to n,
	//-1 if not found
	cout << ternarySearch(arr, 1, 0, arr.size() - 1) << " " << ternarySearch(arr, 6, 0, arr.size() - 1) << endl;

	//first 3 found
	cout << ternarySearch(arr, 3, 0, arr.size() - 1);
}