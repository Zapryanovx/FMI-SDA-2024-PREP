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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* iter = head;
        while(iter != nullptr)
        {
            while(iter->next && iter->val == iter->next->val)
            {
                cout << iter->val << " " << iter->next->val << endl;
                iter->next = iter->next->next;

            }

            iter = iter->next;

        }


        return head;
    }
};
