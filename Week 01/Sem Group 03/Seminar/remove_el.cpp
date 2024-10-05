#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }

    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it == k)
        {
            v.erase(it--);
        }
    }

    size_t size = v.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << v[i] << " ";
    }

    return 0;
}
