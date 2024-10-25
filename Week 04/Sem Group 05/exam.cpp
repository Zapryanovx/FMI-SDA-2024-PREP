#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(unsigned int F, unsigned long long N, unsigned int mid)
{
	long long count = mid - F + 1;
	long long sum = count * (2 * F + count - 1) / 2;
	return sum >= N;
}

int main()
{
	unsigned long long N;
	unsigned int F;

	cin >> N >> F;

	unsigned int left = F;
	unsigned int right = N;

	unsigned int ans = -1;
	while (left <= right)
	{
		unsigned int mid = left + (right - left) / 2;
		if (check(F, N, mid))
		{
			ans = mid - F + 1;
			right = mid - 1;
		}

		else
		{
			left = mid + 1;
		}
	}

	cout << ans;
}