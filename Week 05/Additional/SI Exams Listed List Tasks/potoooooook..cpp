// https://www.hackerrank.com/contests/si-practice-4/challenges/challenge-1645
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
};


int main() {

    ListNode* head = new ListNode;
    ListNode* iter = head;

    int node;
    while (cin >> node)
    {
        iter->next = new ListNode(node);
        iter = iter->next;
    }

    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    long long sum = 0;

    head = head->next;
    while (head)
    {
        minVal = min(head->val, minVal);
        maxVal = max(head->val, maxVal);
        sum += head->val;
        head = head->next;
    }

    cout << minVal << " " << maxVal << " " << sum << endl;

    return 0;
}