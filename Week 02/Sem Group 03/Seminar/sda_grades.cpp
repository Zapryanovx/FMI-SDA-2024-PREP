#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long m, n;
    std::cin >> m >> n;

    std::vector<long long> grades(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> grades[i];
        sum += grades[i];
    }

    if (sum / n >= m)
    {
        std::cout << "yes";
    }

    else
    {
        std::cout << "no";
    }



    return 0;
}
