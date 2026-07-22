# https://leetcode.com/problems/insertion-sort-list/description/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head

        sorted_ll = ListNode()
        curr = head

        while curr is not None:

            next_node = curr.next
            place = sorted_ll

            while place.next is not None and curr.val > place.next.val:
                place = place.next

            curr.next = place.next
            place.next = curr
            curr = next_node

        return sorted_ll.next
