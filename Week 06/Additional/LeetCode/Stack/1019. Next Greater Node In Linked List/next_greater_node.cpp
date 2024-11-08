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
    vector<int> nextLargerNodes(ListNode* head) {

        stack<pair<int, int>> st;
        vector<pair<int, int>> v;

        int counter = 0;
        while (head)
        {
            v.push_back({ head->val, counter++ });
            head = head->next;
        }

        vector<int> res(v.size(), 0);
        for (int i = 0; i < v.size(); i++)
        {
            while (!st.empty() && st.top().first < v[i].first)
            {
                res[st.top().second] = v[i].first;
                st.pop();
            }

            st.push({ v[i].first, i });
        }

        return res;
    }
};