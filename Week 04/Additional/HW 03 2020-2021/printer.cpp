#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

bool check(vector<long long>& v, long long ans, long long goal)
{
	long long printMax = 0;
	for (auto p : v)
	{
		printMax += ans / p;
	}

	return printMax >= goal;
}

int main()
{
	long long n, k;
	cin >> n >> k;

	vector<long long> v(k);

	long long maxTime = LLONG_MIN;
	long long minTime = LLONG_MAX;
	for (size_t i = 0; i < k; i++)
	{
		cin >> v[i];
		maxTime = max(v[i], maxTime);
		minTime = min(v[i], minTime);
	}

	long long left = (n / k) * minTime;
	long long right = (n / k + 1) * maxTime;

	long long ans = right;

	while (left <= right)
	{
		long long mid = left + (right - left) / 2;
		if (check(v, mid, n))
		{
			ans = min(mid, ans);
			right = mid - 1;
		}

		else
		{
			left = mid + 1;
		}
	}
	
	cout << ans;
}