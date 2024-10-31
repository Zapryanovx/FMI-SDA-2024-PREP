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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* removeAt(ListNode* head, int n)
    {
        ListNode* curr = new ListNode(0);
        curr->next = head;

        ListNode* currHead = curr;

        int idx = 1;
        while (idx < n)
        {
            curr = curr->next;
            idx++;
        }

        ListNode* nextNode = curr->next->next;
        delete curr->next;
        curr->next = nextNode;

        return currHead->next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next)
        {
            return nullptr;
        }

        head = reverse(head);
        head = removeAt(head, n);
        head = reverse(head);

        return head;
    }
};