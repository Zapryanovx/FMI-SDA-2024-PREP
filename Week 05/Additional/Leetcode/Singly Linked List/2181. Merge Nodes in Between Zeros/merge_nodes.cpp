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
    ListNode* mergeNodes(ListNode* head) {

        ListNode* res = new ListNode(0);
        ListNode* resHead = res;

        int sum = 0;
        while (head->next)
        {
            if (head->next->val == 0)
            {
                res->next = new ListNode(sum);
                res = res->next;
                sum = 0;
            }

            else
            {
                sum += head->next->val;
            }

            head = head->next;
        }

        return resHead->next;
    }
};