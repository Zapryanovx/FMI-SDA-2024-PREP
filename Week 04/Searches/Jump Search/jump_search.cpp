#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jumpSearch(vector<int>& arr, int x)
{
	int N = arr.size();
	int block_size = sqrt(N);
	
	int step = block_size;
	int prev = 0;

	while (arr[min(step, N) - 1] < x)
	{
		prev = step;
		step += block_size;
		if (prev >= N)
		{
			return -1;
		}
	}

	while (arr[prev] < x)
	{
		prev++;
		if (prev == min(step, N))
		{
			return -1;
		}
	}

	if (arr[prev] == x)
	{
		return prev;
	}

	return -1;
}

int main()
{

	vector<int> arr = { 1, 2, 3, 3, 3, 3, 3, 4, 5 };

	//pos is 0 to n,
	//-1 if not found
	cout << jumpSearch(arr, 1) << " " << jumpSearch(arr, 6) << endl;

	cout << jumpSearch(arr, 3);
}