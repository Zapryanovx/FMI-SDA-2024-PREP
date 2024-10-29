/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {

        Node* curr = head;

        while (curr)
        {
            Node* nextEl = curr->next;
            if (curr->child)
            {
                Node* childAt = flatten(curr->child);

                curr->next = childAt;
                childAt->prev = curr;

                while (childAt->next)
                {
                    childAt = childAt->next;
                }

                childAt->next = nextEl;
                if (nextEl)
                {
                    nextEl->prev = childAt;
                }

                curr->child = nullptr;
            }

            curr = nextEl;
        }

        return head;
    }
};