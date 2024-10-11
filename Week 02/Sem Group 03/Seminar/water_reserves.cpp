#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int N;
    std::cin >> N;

    std::vector<int> walls(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> walls[i];
    }

    int left = 0;
    int right = walls.size() - 1;
    int max = std::min(walls[0], walls[1]);
    while (left != right)
    {
        int curr = std::min(walls[left], walls[right]) * (right - left);
        if (curr > max)
        {
            max = curr;
        }


        if (walls[left] > walls[right])
        {
            right--;
        }

        else
        {
            left++;
        }
    }

    std::cout << max << std::endl;

}
