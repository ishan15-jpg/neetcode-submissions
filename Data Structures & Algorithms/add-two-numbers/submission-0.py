# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        answer = cur = ListNode(-1)
        while l1 and l2:
            tmp = l1.val + l2.val + carry
            if tmp > 9: 
                tmp %= 10
                carry = 1
            else: carry = 0
            ans =  ListNode(tmp)
            cur.next = ans
            cur = ans
            l1 = l1.next
            l2 = l2.next
        while l1:
            tmp = l1.val + carry
            if tmp > 9:
                tmp %= 10
                carry = 1
            else: carry = 0
            ans = ListNode(tmp)
            cur.next = ans
            cur = ans
            l1 = l1.next
        while l2:
            tmp = l2.val + carry
            if tmp > 9:
                tmp %= 10
                carry = 1
            else: carry = 0
            ans = ListNode(tmp)
            cur.next = ans
            cur = ans
            l2 = l2.next
        if carry:
            cur.next = ListNode(1)
        return answer.next
        