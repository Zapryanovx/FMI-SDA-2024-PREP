#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++)
    {
        int n;
        std::string str;
        std::cin >> n >> str;

        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == str[j + 1])
            {
                count++;
            }
        }

        std::cout << count << std::endl;
    }




    return 0;
}