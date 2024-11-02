// https://www.hackerrank.com/contests/sda-test-2022-2023-wdfgs/challenges

void SinglyLinkedList::replace(int X)
{
    if (!head || X == 1)
    {
        return;
    }

    Node* curr = head;

    while (curr)
    {
        if (curr->value == X)
        {
            Node* lastNode = curr->next;
            curr->value = 1;
            curr->next = nullptr;
            size += X - 1;

            for (int i = 0; i < X - 1; i++)
            {
                Node* newNode = new Node(1);
                curr->next = newNode;
                curr = curr->next;
            }
            curr->next = lastNode;

            if (!lastNode)
            {
                tail = curr;
            }
        }

        curr = curr->next;
    }
}