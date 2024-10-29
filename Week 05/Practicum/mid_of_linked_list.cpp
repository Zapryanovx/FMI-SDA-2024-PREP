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
    ListNode* middleNode(ListNode* head) {

        int size = 0;
        ListNode* mid = head;
        ListNode* end = head;

        while (end != nullptr && end->next != nullptr)
        {
            mid = mid->next;
            end = end->next->next;
        }

        return mid;
    }
};