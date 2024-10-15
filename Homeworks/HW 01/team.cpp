#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getIdx(char ch)
{
    if (isupper(ch))
    {
        return ch - 'A' + 36;
    }
    if (islower(ch)) {
        return ch - 'a' + 10;
    }
    return ch - '0';
}


char getSymbol(int index)
{
    if (index >= 36 && index <= 61)
    {
        return 'A' + index - 36;
    }

    if (index >= 10 && index <= 35)
    {
        return 'a' + index - 10;
    }
    return index + '0';
}

int main() {

    int n;
    cin >> n;

    string players;
    cin >> players;

    int symbols[63]{};

    for (size_t i = 0; i < players.size(); i++)
    {
        symbols[getIdx(players[i])]++;
    }

    for (size_t i = 0; i < 63; i++)
    {
        while (symbols[i]--)
        {
            cout << getSymbol(i);
        }
    }

    return 0;
}
