// https://www.hackerrank.com/contests/sda-test2/challenges/--82/problem

void removeComplex(int devidedBy) {

    Node* dummy = new Node(nullptr, 0);
    dummy->next = head;

    Node* curr = dummy;
    while (curr->next)
    {
        if (curr->next->data % devidedBy == 0)
        {
            Node* nextNode = curr->next->next;
            delete curr->next;
            curr->next = nextNode;
        }

        else
        {
            curr = curr->next;
        }
    }

    head = dummy->next;
}