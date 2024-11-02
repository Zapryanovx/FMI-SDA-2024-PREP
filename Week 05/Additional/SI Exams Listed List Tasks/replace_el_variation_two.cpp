// https://www.hackerrank.com/contests/sda-test-2022-2023-wdfgs/challenges/challenge-3730

void SinglyLinkedList::replace(int X)
{
    if (X < 0 || X >= size)
    {
        return;
    }

    int index = X;
    Node* find = head;
    while (index > 0)
    {
        index--;
        find = find->next;
    }

    int lookFor = find->value;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* curr = dummy;
    while (curr->next->next)
    {
        if (curr->next->value == lookFor)
        {
            curr->next->value = curr->next->next->value;
        }

        curr = curr->next;
    }

    head = dummy->next;
    delete dummy;
}