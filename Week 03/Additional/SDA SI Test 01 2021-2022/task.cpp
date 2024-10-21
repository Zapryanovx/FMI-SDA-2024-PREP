#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums, vector<int>& temp, int leftStart, int rightStart, int rightEnd)
{
    int leftIndex = leftStart;
    int leftEnd = rightStart - 1;

    int rightIndex = rightStart;
    int currIndex = leftStart;

    while (leftIndex <= leftEnd && rightIndex <= rightEnd)
    {

        if (nums[leftIndex] < nums[rightIndex])
        {
            temp[currIndex++] = nums[leftIndex++];
        }

        else
        {
            temp[currIndex++] = nums[rightIndex++];
        }

    }

    while (leftIndex <= leftEnd)
    {
        temp[currIndex++] = nums[leftIndex++];
    }

    while (rightIndex <= rightEnd)
    {
        temp[currIndex++] = nums[rightIndex++];
    }

    for (size_t i = leftStart; i <= rightEnd; i++)
    {
        nums[i] = temp[i];
    }
}

void mergeSort(vector<int>& nums, vector<int>& temp, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(nums, temp, left, mid);
    mergeSort(nums, temp, mid + 1, right);
    merge(nums, temp, left, mid + 1, right);
}


void mergeSort(vector<int>& nums)
{
    vector<int> temp(nums.size());

    mergeSort(nums, temp, 0, nums.size() - 1);
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    mergeSort(nums);

    cout << nums[0] << " ";
    for (size_t i = 1; i < n; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            cout << nums[i] << " ";
        }
    }

    return 0;
}
