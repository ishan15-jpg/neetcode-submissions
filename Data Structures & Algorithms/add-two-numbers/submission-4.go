/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    answer := &ListNode{-1,nil}
    cur := answer
    carry := 0
    for l1 != nil && l2 != nil {
        tmp := l1.Val + l2.Val + carry
        if tmp > 9 {
            carry = 1
        } else { carry = 0 }
        cur.Next = &ListNode{tmp%10,nil}
        cur = cur.Next
        l1,l2 = l1.Next,l2.Next
    }
    for l1 != nil {
        tmp := l1.Val + carry
        if tmp > 9 {
            carry = 1
        } else { carry = 0 }
        cur.Next = &ListNode{tmp%10,nil}
        cur = cur.Next
        l1 = l1.Next
    }
    for l2 != nil {
        tmp := l2.Val + carry
        if tmp > 9 {
            carry = 1
        } else { carry = 0 }
        cur.Next = &ListNode{tmp%10,nil}
        cur = cur.Next
        l2 = l2.Next
    }
    if carry == 1 { cur.Next = &ListNode{1,nil} }
    return answer.Next
}
