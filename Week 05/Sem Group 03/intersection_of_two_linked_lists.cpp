/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* routeA = headA;
        ListNode* routeB = headB;

        while (routeA != routeB)
        {
            routeA = routeA ? routeA->next : headB;
            routeB = routeB ? routeB->next : headA;
        }

        return routeA;
    }
};