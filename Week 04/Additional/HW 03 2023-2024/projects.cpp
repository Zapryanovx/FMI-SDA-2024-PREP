#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    long long N, D;
    cin >> N >> D;

    vector<long long> projects(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> projects[i];
    }

    sort(projects.begin(), projects.end());

    int first = 0;
    int second = 0;

    int counter = 0;

    while (first < N && second < N)
    {
        if (abs(projects[first] - projects[second]) == D)
        {
            counter++;
            first++;
            second++;
        }

        else if (abs(projects[first] - projects[second]) < D)
        {
            first++;
        }

        else
        {
            second++;
        }
    }

    cout << counter;


    return 0;
}