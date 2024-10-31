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
    int getDecimalValue(ListNode* head) {
        
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL)
        {
            temp = temp->next;
            size++;
        }

        int num = 0;
        int powOfTwo = size - 1;
        while(head != NULL)
        {
            num += (head->val << powOfTwo);
            head = head->next;
            powOfTwo--;
        }

        return num;

    }
};
