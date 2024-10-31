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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* res = new ListNode(0);
        ListNode* iter = res;

        int carry = 0;
        while (true)
        {
            int sum = 0;
            if (l1 && l2)
            {
                sum += l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }

            else if (l1)
            {
                sum += l1->val + carry;
                l1 = l1->next;
            }

            else if (l2)
            {
                sum += l2->val + carry;
                l2 = l2->next;
            }

            if (sum < 10)
            {
                iter->next = new ListNode(sum);
                carry = 0;
            }

            else
            {
                iter->next = new ListNode(sum % 10);
                carry = sum / 10;
            }

            iter = iter->next;
            if (!l1 && !l2)
            {
                break;
            }

        }

        if (carry)
        {
            iter->next = new ListNode(carry);
        }

        return res->next;
    }
};