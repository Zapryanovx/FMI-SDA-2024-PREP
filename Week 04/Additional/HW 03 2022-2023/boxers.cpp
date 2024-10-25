#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    int minWeight, maxWeight;

    cin >> N >> Q;

    vector<int> boxers(N);
    for (size_t i = 0; i < boxers.size(); i++)
    {
        cin >> boxers[i];
    }

    sort(boxers.begin(), boxers.end());
    for (size_t i = 0; i < Q; i++)
    {
        cin >> minWeight >> maxWeight;

        if (minWeight > maxWeight)
        {
            cout << 0 << endl;
            continue;
        }

        auto left = lower_bound(boxers.begin(), boxers.end(), minWeight);
        auto right = upper_bound(boxers.begin(), boxers.end(), maxWeight);

        cout << distance(left, right) << endl;
    }



    return 0;
}
