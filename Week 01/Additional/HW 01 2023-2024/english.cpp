#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string word;
    int n;
    char symbol;

    std::cin >> word >> n >> symbol;

    int count = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == symbol)
        {
            count++;
        }
    }

    count *= (n / word.size());
    int symbolsLeft = n % word.size();

    for (int i = 0; i < symbolsLeft; i++)
    {
        if (word[i] == symbol)
        {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}