#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    std::cin >> n;

    std::vector<int> digits(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> digits[i];
    }

    int plusOne = 1;
    for (auto it = digits.end() - 1; it != digits.begin(); it--)
    {
        int newDigit = (*it) + plusOne;
        if (newDigit == 10)
        {
            (*it) = 0;
            plusOne = 1;
        }

        else
        {
            (*it)++;
            plusOne = 0;
            break;
        }
    }

    //if one more digit (ex. 99 -> 100)
    if (plusOne == 1)
    {
        *(digits.begin()) = 0;
        digits.insert(digits.begin(), 1);
    }

    size_t size = digits.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << digits[i];
    }


    return 0;
}