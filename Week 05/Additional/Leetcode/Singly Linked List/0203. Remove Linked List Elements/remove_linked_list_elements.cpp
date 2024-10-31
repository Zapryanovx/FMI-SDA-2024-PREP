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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* res = new ListNode(0);
        res->next = head;

        ListNode* iter = res;
        while(iter->next != nullptr)
        {
            if(iter->next->val == val)
            {
                iter->next = iter->next->next;
            }

            else
            {
                iter = iter->next;
            }
        }

        //memory leak handle
        ListNode* cpyRes = res->next;
        delete res;

        return cpyRes;
    }
};
