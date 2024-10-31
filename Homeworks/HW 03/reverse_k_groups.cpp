#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    ListNode* next = nullptr;
    int val;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode* reversePart(ListNode* newHead, int left, int right)
{
    ListNode* lastLeftPart = nullptr;
    ListNode* curr = newHead;
    int idx = 1;

    while (idx < left)
    {
        lastLeftPart = curr;
        curr = curr->next;
        idx++;
    }

    ListNode* firstRightPart = curr;
    ListNode* prev = nullptr;

    while (idx <= right && curr)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        idx++;
    }

    if (lastLeftPart)
    {
        lastLeftPart->next = prev;
    }

    else
    {
        newHead = prev;
    }

    firstRightPart->next = curr;
    return newHead;
}

ListNode* reverse(ListNode* head, int n)
{

    ListNode* curr = head;
    ListNode* prevEnd = nullptr;

    while (true)
    {
        ListNode* temp = curr;
        int count = 0;
        while (temp && count < n)
        {
            temp = temp->next;
            count++;
        }

        if (count < n)
        {
            break;
        }

        ListNode* reversed = reversePart(curr, 1, n);
        if (prevEnd)
        {
            prevEnd->next = reversed;
        }

        else
        {
            head = reversed;
        }

        prevEnd = curr;
        curr = prevEnd->next;
    }

    return head;
}

int main()
{
    int k;
    cin >> k;

    int val;
    cin >> val;

    ListNode* head = new ListNode(val);
    ListNode* input = head;

    for (int i = 1; i < k; i++)
    {
        cin >> val;
        input->next = new ListNode(val);
        input = input->next;
    }

    int n;
    cin >> n;

    head = reverse(head, n);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

}