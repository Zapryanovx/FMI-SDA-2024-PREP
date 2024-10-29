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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* start = new ListNode;
        ListNode* curr = start;

        while (true)
        {
            ListNode* nextMin = nullptr;
            int fromIdx = -1;

            for (size_t i = 0; i < lists.size(); i++)
            {
                if (lists[i] && (!nextMin || lists[i]->val < nextMin->val))
                {
                    nextMin = lists[i];
                    fromIdx = i;
                }
            }

            if (!nextMin)
            {
                break;
            }

            curr->next = nextMin;
            curr = curr->next;
            lists[fromIdx] = lists[fromIdx]->next;
        }

        return start->next;
    }
};