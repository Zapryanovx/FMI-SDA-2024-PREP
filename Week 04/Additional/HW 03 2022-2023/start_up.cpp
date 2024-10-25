#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool divide(vector<int>& employees, long long target, int T)
{
    int teams = 1;
    long long currSkills = 0;

    for (size_t i = 0; i < employees.size(); i++)
    {
        if (employees[i] > target)
        {
            return false;
        }

        currSkills += employees[i];
        if (currSkills > target)
        {
            teams++;
            currSkills = employees[i];
        }
    }

    return teams <= T;
}

int main()
{
    int n, t;
    cin >> n >> t;

    int maxSkills = -1;
    long long totalSkills = 0;

    vector<int> employees(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> employees[i];

        totalSkills += employees[i];
        maxSkills = max(maxSkills, employees[i]);
    }

    long long left = maxSkills;
    long long right = totalSkills;

    long long minTeam = 0;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;

        if (divide(employees, mid, t))
        {
            minTeam = mid;
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }

    cout << minTeam;



    return 0;
}
