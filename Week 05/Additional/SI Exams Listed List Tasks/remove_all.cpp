// https://www.hackerrank.com/contests/sda-2021-2021-test-2-test/challenges/challenge-3111/problem

void SinglyLinkedList::removeAll(int X)
{
    Node* res = new Node(0);
    res->next = head;

    Node* curr = res;

    while (curr->next)
    {
        if (curr->next->value == X)
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

    head = res->next;

}