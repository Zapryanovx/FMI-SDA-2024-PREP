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

    int sizeOf(ListNode* head)
    {
        int size = 0;
        while (head)
        {
            head = head->next;
            size++;
        }

        return size;
    }

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

    void sumOfHalf(vector<int>& sums, ListNode* head)
    {
        ListNode* curr = head;
        for (size_t i = 0; i < sums.size(); i++)
        {
            sums[i] += curr->val;
            curr = curr->next;
        }
    }

    int pairSum(ListNode* head) {

        int size = sizeOf(head);
        vector<int> sums(size / 2, 0);

        sumOfHalf(sums, head);
        ListNode* reversed = reverse(head);
        sumOfHalf(sums, reversed);

        return *max_element(sums.begin(), sums.end());
    }
};