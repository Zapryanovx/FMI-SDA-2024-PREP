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
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        
        ListNode* mid = head;
        ListNode* end = head;

        while(end != nullptr && end->next != nullptr)
        {
            mid = mid->next;
            end = end->next->next;
        }

        ListNode* secondHalf = reverseList(mid);
        while(secondHalf != nullptr)
        {
            if(head->val != secondHalf->val)
            {
                return false;
            }

            head = head->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};
