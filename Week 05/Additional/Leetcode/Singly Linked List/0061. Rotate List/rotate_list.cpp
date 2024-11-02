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

    ListNode* getTail(ListNode* head)
    {
        ListNode* tail = head;
        while (tail->next)
        {
            tail = tail->next;
        }

        return tail;
    }

    int getSize(ListNode* head)
    {
        int size = 0;
        while (head)
        {
            size++;
            head = head->next;
        }

        return size;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if (!head)
        {
            return nullptr;
        }

        int size = getSize(head);
        int end = size - k % size - 1;

        ListNode* tail = getTail(head);
        tail->next = head;

        ListNode* curr = head;
        for (int i = 0; i < end; i++)
        {
            curr = curr->next;
        }

        ListNode* res = curr->next;
        curr->next = nullptr;
        return res;
    }
};