#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    bool isValid = false;

    for (int right = n - 1; right >= 2; right--)
    {
        int leftOne = 0;
        int leftTwo = right - 1;

        while (leftOne < leftTwo)
        {
            int sum = nums[leftOne] + nums[leftTwo];

            if (sum == nums[right])
            {
                isValid = true;
                break;
            }

            else if (sum < nums[right])
            {
                leftOne++;
            }

            else
            {
                leftTwo--;
            }
        }

        if (isValid)
        {
            break;
        }
    }

    if (isValid)
    {
        cout << "true";
    }

    else
    {
        cout << "false";
    }

    return 0;
}
