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
        int size = 0;
        while (head)
        {
            head = head->next;
            size++;
        }

        return size;
    }

    ListNode* swapNodes(ListNode* head, int k) {

        int left = k - 1;
        ListNode* leftNode = head;
        while (left--)
        {
            leftNode = leftNode->next;
        }

        ListNode* rightNode = head;
        int size = getSize(head);
        int right = size - k;
        while (right--)
        {
            rightNode = rightNode->next;
        }

        swap(leftNode->val, rightNode->val);
        return head;
    }
};