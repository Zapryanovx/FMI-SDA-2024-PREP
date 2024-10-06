#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        std::cin >> n >> k;

        std::string data;
        std::cin >> data;

        int failed[26]{};
        for (int i = 0; i < n; i++)
        {
            if (std::isupper(data[i]))
            {
                failed[data[i] - 'A']++;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (failed[i] >= k)
            {
                std::cout << char(i + 'A');
            }
        }
        std::cout << std::endl;


    }

    return 0;
}
