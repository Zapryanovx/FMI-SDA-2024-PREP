/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode* curr = head;
        int idx = 1;

        ListNode* lastFromFirst = head;
        while (idx < left)
        {
            lastFromFirst = curr;
            curr = curr->next;
            idx++;
        }

        ListNode* firstFromSecond = curr;

        ListNode* prev = nullptr;
        while (idx <= right)
        {
            ListNode* nextEl = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextEl;
            idx++;
        }

        if (lastFromFirst)
        {
            lastFromFirst->next = prev;
        }
        else
        {
            head = prev;
        }

        firstFromSecond->next = curr;
        return head;
    }
};