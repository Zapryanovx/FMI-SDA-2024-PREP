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
    ListNode* partition(ListNode* head, int x) {

        ListNode* lower = new ListNode(0);
        ListNode* greater = new ListNode(0);

        ListNode* lowerStart = lower;
        ListNode* greaterStart = greater;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;
        while (curr->next)
        {
            if (curr->next->val < x)
            {
                lower->next = new ListNode(curr->next->val);
                lower = lower->next;
            }

            else
            {
                greater->next = new ListNode(curr->next->val);
                greater = greater->next;
            }

            curr = curr->next;
        }

        lower->next = greaterStart->next;
        head = lowerStart->next;
        return head;
    }
};