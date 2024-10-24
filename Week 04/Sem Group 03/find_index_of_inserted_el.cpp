#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getInsertedIdx(vector<int>& X, vector<int>& Y)
{
	int left = 0;
	int right = X.size() - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (Y[mid] == -1)
		{
			return mid;
		}

		if (Y[mid] == X[mid])
		{
			left = mid + 1;
		}

		else
		{
			right = mid - 1;
		}
	}

	return -1;
}

int main()
{
	vector<int> X = { 5, 2, 9, 1 };
	vector<int> Y = { 5, -1, 2, 9, 1 };
	
	cout << getInsertedIdx(X, Y);
}