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

    int getSize(ListNode* head)
    {
        int count = 0;
        while (head)
        {
            head = head->next;
            count++;
        }

        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {

        int size = getSize(head);
        int perCell = size / k;
        int left = size % k;

        vector<ListNode*> res(k);
        int at = 0;

        while (head)
        {

            int carry = 0;
            if (left > 0)
            {
                carry = 1;
            }

            int count = 0;
            ListNode* last = head;
            while (count < perCell + carry - 1)
            {
                count++;
                last = last->next;
            }

            left--;
            res[at++] = head;
            ListNode* nextNode = last->next;
            last->next = nullptr;
            head = nextNode;

            if (left < 0)
            {
                left = 0;
            }
        }

        return res;
    }
};