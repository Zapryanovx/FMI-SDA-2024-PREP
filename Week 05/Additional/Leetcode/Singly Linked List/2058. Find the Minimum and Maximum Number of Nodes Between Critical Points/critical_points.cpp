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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
        {
            return { -1, -1 };
        }

        ListNode* prevPoint = head;
        ListNode* currPoint = head->next;
        ListNode* nextPoint = head->next->next;
        int at = 1;

        vector<int> pos;
        while (nextPoint)
        {
            if (prevPoint->val < currPoint->val && currPoint->val > nextPoint->val)
            {
                pos.push_back(at);
            }

            else if (prevPoint->val > currPoint->val && currPoint->val < nextPoint->val)
            {
                pos.push_back(at);
            }

            at++;
            prevPoint = prevPoint->next;
            currPoint = currPoint->next;
            nextPoint = nextPoint->next;
        }

        if (pos.size() < 2)
        {
            return { -1, -1 };
        }

        int minDist = INT_MAX;
        int maxDist = pos[pos.size() - 1] - pos[0];
        for (int i = 1; i < pos.size(); i++)
        {
            minDist = min(pos[i] - pos[i - 1], minDist);
        }

        return { minDist, maxDist };
    }
};