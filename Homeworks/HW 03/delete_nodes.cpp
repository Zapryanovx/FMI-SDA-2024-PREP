/*
 * Complete the 'removeDuplicates' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST llist as parameter.
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

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {

    SinglyLinkedListNode* res = new SinglyLinkedListNode(0);
    res->next = llist;

    SinglyLinkedListNode* iter = res;
    while (iter)
    {
        while (iter->next && iter->next->next && iter->next->data == iter->next->next->data)
        {
            iter->next = iter->next->next;
        }

        iter = iter->next;
    }

    return res->next;
}