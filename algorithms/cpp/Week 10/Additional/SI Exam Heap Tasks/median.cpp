// https://www.hackerrank.com/contests/sda-20232024-test-4/challenges/challenge-4442/copy-from/1386386535
#include <bits/stdc++.h>
using namespace std;

void printMedian( priority_queue<int, vector<int>>& left,  priority_queue<int, vector<int>, greater<int>>& right)
{
    if(left.size() == right.size())
    {
        cout << std::fixed << std::setprecision(1) << (1.00 * (left.top() + right.top()) / 2) << endl;
    }
    
    else if(left.size() > right.size())
    {
        cout << std::fixed << std::setprecision(1) << 1.00 * left.top() << endl;
    }
    
    else
    {
        cout << std::fixed << std::setprecision(1) << 1.00 * right.top() << endl;
    }
}

void findMedian(vector<int>& nums)
{
    priority_queue<int, vector<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    for(int num: nums)
    {
        if(left.empty() || left.top() > num)
        {
            left.push(num);
        }
        
        else
        {
            right.push(num);
        }
        
        if(left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        
        else if(right.size() > left.size() + 1)
        {
            left.push(right.top());
            right.pop();
        }
        
        printMedian(left, right);
        
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    
    findMedian(nums);
    
    
    return 0;
}
