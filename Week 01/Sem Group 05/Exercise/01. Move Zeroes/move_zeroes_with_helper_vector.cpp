#include <iostream>
#include <vector>

//Идея:
//ще прехвърлим всички числа различни от 0 в нов вектор,
//след което ще допълним новия вектор с 0, докато не достигнем n
//и запазваме резултата в първоначалния масив

void moveZeroes(std::vector<int>& nums) 
{
    std::vector<int> res(nums.size());
    int resIdx = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            res[resIdx++] = nums[i];
        }
    }

    for (int i = resIdx; i < nums.size(); i++)
    {
        res[i] = 0;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = res[i];
    }
}