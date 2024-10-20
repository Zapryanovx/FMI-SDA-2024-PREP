#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long mergeAndCount(vector<int>& nums, int left, int mid, int right)
{
    vector<int> sorted(right - left + 1);
    int leftIndex = left;
    int rightIndex = mid + 1;
    int currIndex = 0;

    int countInversions = 0;

    while (leftIndex <= mid && rightIndex <= right)
    {
        if (nums[leftIndex] <= nums[rightIndex])
        {
            sorted[currIndex++] = nums[leftIndex++];
        }

        else
        {
            countInversions += (mid - leftIndex + 1);
            sorted[currIndex++] = nums[rightIndex++];
        }
    }

    while (leftIndex <= mid)
    {
        sorted[currIndex++] = nums[leftIndex++];
    }

    while (rightIndex <= right)
    {
        sorted[currIndex++] = nums[rightIndex++];
    }

    for (size_t i = 0; i < sorted.size(); i++)
    {
        nums[left + i] = sorted[i];
    }

    return countInversions;
}

long long mergeSort(vector<int>& nums, int left, int right)
{
    long long countInversions = 0;
    if (left >= right)
    {
        return countInversions;
    }

    int mid = left + (right - left) / 2;
    countInversions += mergeSort(nums, left, mid);
    countInversions += mergeSort(nums, mid + 1, right);
    countInversions += mergeAndCount(nums, left, mid, right);

    return countInversions;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for (size_t i = 0; i < nums.size(); i++)
    {
        cin >> nums[i];
    }

    long long countInversions = mergeSort(nums, 0, nums.size() - 1);
    cout << countInversions;

    return 0;
}
