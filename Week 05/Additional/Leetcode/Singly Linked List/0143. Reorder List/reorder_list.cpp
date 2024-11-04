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

    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* left = head;
        ListNode* right = slow->next;
        slow->next = nullptr;

        right = reverse(right);

        ListNode* res = left;
        while (left && right)
        {
            ListNode* nextLeft = left->next;
            ListNode* nextRight = right->next;

            left->next = right;
            left->next->next = nextLeft;

            left = nextLeft;
            right = nextRight;
        }

        head = res;
    }
};