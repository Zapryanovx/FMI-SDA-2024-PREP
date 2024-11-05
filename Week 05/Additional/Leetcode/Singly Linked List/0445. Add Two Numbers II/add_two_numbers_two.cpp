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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverse(l1);
        ListNode* l1Start = l1;

        l2 = reverse(l2);

        int carry = 0;
        ListNode* prev = l1;

        while (l1 && l2)
        {
            int sum = l1->val + l2->val + carry;
            if (sum >= 10)
            {
                l1->val = sum % 10;
                carry = sum / 10;
            }

            else
            {
                l1->val = sum;
                carry = 0;
            }

            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            int sum = l1->val + carry;
            if (sum >= 10)
            {
                l1->val = sum % 10;
                carry = sum / 10;
            }

            else
            {
                l1->val = sum;
                carry = 0;
            }

            prev = l1;
            l1 = l1->next;
        }


        while (l2)
        {
            int sum = l2->val + carry;
            cout << sum << endl;
            if (sum >= 10)
            {
                prev->next = new ListNode(sum % 10);
                carry = sum / 10;
            }

            else
            {
                prev->next = new ListNode(sum);
                carry = 0;
            }

            prev = prev->next;
            l2 = l2->next;
        }

        if (carry)
        {
            prev->next = new ListNode(carry);
        }

        l1Start = reverse(l1Start);
        return l1Start;
    }
};