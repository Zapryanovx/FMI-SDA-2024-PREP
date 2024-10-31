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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {

        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, -1));

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        int row = 0, col = 0;
        int goTo = 0;

        while (head)
        {
            matrix[row][col] = head->val;
            head = head->next;

            //right
            if (goTo == 0)
            {
                if (col < right)
                {
                    col++;
                }

                else
                {
                    goTo = 1;
                    top++;
                    row++;
                }

            }

            //down
            else if (goTo == 1)
            {
                if (row < bottom)
                {
                    row++;
                }

                else
                {
                    goTo = 2;
                    right--;
                    col--;
                }

            }

            //left
            else if (goTo == 2)
            {
                if (col > left)
                {
                    col--;
                }

                else
                {
                    goTo = 3;
                    bottom--;
                    row--;
                }

            }

            //up
            else if (goTo == 3)
            {
                if (row > top)
                {
                    row--;
                }

                else
                {
                    goTo = 0;
                    left++;
                    col++;
                }
            }
        }

        return matrix;
    }
};