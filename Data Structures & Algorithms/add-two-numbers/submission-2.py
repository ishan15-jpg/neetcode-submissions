# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def __init__(self):
        self.carry = 0

    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        if not l1 and not l2 and not self.carry: return None
        curr_digit = (l1.val if l1 else 0) + (l2.val if l2 else 0) + self.carry
        self.carry = 1 if curr_digit > 9 else 0
        node = ListNode(curr_digit%10)
        node.next = self.addTwoNumbers(l1.next if l1 else None,l2.next if l2 else None)
        return node 