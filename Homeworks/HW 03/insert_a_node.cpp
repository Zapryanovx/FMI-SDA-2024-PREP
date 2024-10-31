/*
 * Complete the 'insertNodeAtPosition' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST llist
 *  2. INTEGER data
 *  3. INTEGER position
 */

 /*
  * For your reference:
  *
  * SinglyLinkedListNode {
  *     int data;
  *     SinglyLinkedListNode* next;
  * };
  *
  */

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {

    SinglyLinkedListNode* llistStart = llist;

    int idx = 1;
    while (idx < position)
    {
        llist = llist->next;
        idx++;
    }

    SinglyLinkedListNode* nextNode = llist->next;
    SinglyLinkedListNode* inserted = new SinglyLinkedListNode(data);
    inserted->next = nextNode;
    llist->next = inserted;

    return llistStart;
}