#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> first(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> first[i];
    }

    int m;
    cin >> m;

    vector<int> second(m);
    for (size_t i = 0; i < m; i++)
    {
        cin >> second[i];
    }

    vector<int> intersection;
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (first[i] == second[j])
        {
            intersection.push_back(first[i]);
            i++;
            j++;
        }

        else if (first[i] < second[j])
        {
            i++;
        }

        else
        {
            j++;
        }

        while (i < n && i > 0 && first[i] == first[i - 1])
        {
            i++;
        }

        while (j < n && j > 0 && second[j] == second[j - 1])
        {
            j++;
        }

    }

    int sum = 0;
    for (size_t i = 0; i < intersection.size(); i++)
    {
        sum += intersection[i];
    }

    cout << sum;


    return 0;
}
