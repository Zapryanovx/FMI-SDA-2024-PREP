// https://www.hackerrank.com/contests/sda-2021-2021-test-2-test/challenges/challenge-3113/problem

void SinglyLinkedList::group(int start, int end)
{
    if (!head || start < 0 || end < 0 || start >= size || end >= size || start>end)
    {
        std::cout << "fail_grouping";
        return;
    }

    if (start == end)
    {
        return;
    }

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* curr = dummy;

    int index = 0;
    int sum = 0;

    Node* lastNode = dummy;
    Node* nextNode = nullptr;
    while (curr->next)
    {
        if (start - 1 == index)
        {
            lastNode = curr->next;
        }

        if (end + 1 == index)
        {
            nextNode = curr->next;
        }

        if (start <= index && index <= end)
        {
            sum += curr->next->value;
        }

        index++;
        curr = curr->next;
    }

    Node* newNode = new Node(sum);
    lastNode->next = newNode;
    newNode->next = nextNode;

    head = dummy->next;
}