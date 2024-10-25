#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool check(vector<unsigned int> cables, unsigned int mid, unsigned int K)
{
	long long total = 0;
	for (size_t i = 0; i < cables.size(); i++)
	{
		total += cables[i] / mid;
	}

	return total >= K;
}

int main()
{

	unsigned int N, K;
	cin >> N >> K;
	
	vector<unsigned int> cables(N);
	
	unsigned int maxCable = 0;

	for (size_t i = 0; i < N; i++)
	{
		cin >> cables[i];
		maxCable = max(cables[i], maxCable);
	}

	unsigned int left = 1;
	unsigned int right = maxCable;

	long long ans = 0;

	while (left <= right)
	{
		unsigned int mid = left + (right - left) / 2;
		if (check(cables, mid, K))
		{
			ans = mid;
			left = mid + 1;
		}

		else
		{
			right = mid - 1;
		}
	}

	cout << ans;
}