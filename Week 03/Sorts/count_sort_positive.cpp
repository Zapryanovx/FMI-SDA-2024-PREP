#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int>& arr)
{
	int N = arr.size();
	if (N == 0)
		return;

	int K = *max_element(arr.begin(), arr.end()) + 1;

	vector<int> output(N);
	vector<int> count(K, 0);

	for (int i = 0; i < N; i++)
	{
		count[arr[i]]++;
	}

	for (int i = 1; i < K; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0; i < N; i++)
	{
		arr[i] = output[i];
	}

}

int main()
{
	int n;
	std::cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	counting_sort(nums);

	for (int i = 0; i < n; i++)
	{
		cout<<nums[i] << " ";
	}
}
