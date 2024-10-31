// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode* res = new SinglyLinkedListNode(0);

    SinglyLinkedListNode* iter = res;
    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            iter->next = head1;
            head1 = head1->next;
        }

        else
        {
            iter->next = head2;
            head2 = head2->next;
        }

        iter = iter->next;
    }

    if (head1)
    {
        iter->next = head1;
    }

    if (head2)
    {
        iter->next = head2;
    }

    return res->next;

}