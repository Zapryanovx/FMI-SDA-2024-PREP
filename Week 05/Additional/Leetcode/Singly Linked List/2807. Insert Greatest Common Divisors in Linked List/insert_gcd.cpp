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

int gcd(int a, int b) {

    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a - b, b);

    return gcd(a, b - a);
}
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode* curr = head;
        while (curr->next)
        {
            int commonDiv = gcd(curr->val, curr->next->val);
            ListNode* toInsert = new ListNode(commonDiv);

            ListNode* nextNode = curr->next;
            curr->next = toInsert;
            toInsert->next = nextNode;

            curr = nextNode;
        }

        return head;
    }
};