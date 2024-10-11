#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str;
    std::cin >> str;

    int idx = 0;
    int count = 1;
    while (idx < str.size())
    {
        if (str[idx] == str[idx + 1])
        {
            count++;
        }

        else
        {
            std::cout << count << str[idx];
            count = 1;
        }

        idx++;
    }

    return 0;
}
