// https://www.hackerrank.com/contests/sda-2021-2021-test-2-test/challenges/challenge-3112/problem

int SinglyLinkedList::count(int X)
{
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* curr = dummy;
    int count = 0;
    while (curr->next)
    {
        if (curr->next->value == X)
        {
            count++;
        }

        curr = curr->next;
    }

    delete dummy;
    return count;
}