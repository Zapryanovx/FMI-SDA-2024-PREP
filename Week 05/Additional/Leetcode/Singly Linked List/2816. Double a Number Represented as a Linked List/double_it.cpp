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

    ListNode* doubleIt(ListNode* head) {

        ListNode* reversed = new ListNode(0);
        reversed->next = reverse(head);

        ListNode* curr = reversed;
        int carry = 0;

        while (curr->next)
        {
            int doubled = curr->next->val * 2 + carry;
            if (doubled > 9)
            {
                curr->next->val = doubled % 10;
                carry = doubled / 10;
            }

            else
            {
                curr->next->val = doubled;
                carry = 0;
            }

            curr = curr->next;
        }

        if (carry)
        {
            curr->next = new ListNode(carry);
        }

        head = reverse(reversed->next);
        return head;
    }
};