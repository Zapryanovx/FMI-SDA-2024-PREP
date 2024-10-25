//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//
//int main() {
//
//    int n, q;
//    cin >> n >> q;
//
//    vector<int> students(n);
//    for (size_t i = 0; i < n; i++)
//    {
//        cin >> students[i];
//    }
//
//    sort(students.begin(), students.end());
//
//    int lowCriteria, upCriteria;
//    for (size_t i = 0; i < q; i++)
//    {
//        cin >> lowCriteria >> upCriteria;
//
//        if (lowCriteria > upCriteria)
//        {
//            cout << 0 << endl;
//            continue;
//        }
//
//        auto left = lower_bound(students.begin(), students.end(), lowCriteria);
//        auto right = upper_bound(students.begin(), students.end(), upCriteria);
//
//        cout << distance(left, right) << endl;
//    }
//
//
//    return 0;
//}
