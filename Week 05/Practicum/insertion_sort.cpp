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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode* sorted = new ListNode(0);
        ListNode* curr = head;

        while (curr)
        {
            ListNode* nextNode = curr->next;

            ListNode* search = sorted;
            while (search->next && curr->val > search->next->val)
            {
                search = search->next;
            }

            curr->next = search->next;
            search->next = curr;

            curr = nextNode;
        }

        ListNode* res = sorted->next;
        delete sorted;
        return res;
    }
};