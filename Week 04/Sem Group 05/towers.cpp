#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'hackerlandRadioTransmitters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY x
 *  2. INTEGER k
 */

bool check(vector<int>& x, int mid, int k)
{
    int i = 0;
    int n = x.size();

    while (i < n)
    {
        int range = x[i] + k;
        cout << range << " " << x[i] << " " << mid << endl;
        while (i < n && x[i] <= range)
        {
            i++;
        }

        range = x[--i] + k;
        while (i < n && x[i] <= range)
        {
            i++;
        }

        mid--;
    }

    return mid >= 0;
}

int hackerlandRadioTransmitters(vector<int> x, int k) {

    int minHouse = INT_MAX;
    int maxHouse = INT_MIN;

    for (size_t i = 0; i < x.size(); i++)
    {
        minHouse = min(x[i], minHouse);
        maxHouse = max(x[i], maxHouse);
    }

    sort(x.begin(), x.end());

    int left = minHouse;
    int right = (maxHouse - minHouse + 1) / k;

    cout << left << " " << right << endl;

    int ans = 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        cout << mid << endl;
        if (check(x, mid, k))
        {
            cout << mid << "checked" << endl;
            ans = mid;
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}