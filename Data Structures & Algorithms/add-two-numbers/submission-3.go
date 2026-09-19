/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func add(l1 *ListNode, l2 * ListNode, carry int) *ListNode {
    if l1 == nil && l2 == nil && carry == 0 { return nil }
    v1,v2 := 0,0
    if l1 != nil { v1 = l1.Val } 
    if l2 != nil { v2 = l2.Val }
    tmp := v1 + v2 + carry
    digit := &ListNode{tmp%10,nil}
    if tmp > 9 {
        carry = 1
    } else { carry = 0 }
    if l1 == nil { 
        l1 = nil 
    } else { l1 = l1.Next }
    if l2 == nil {
        l2 = nil
    } else { l2 = l2.Next }
    digit.Next = add(l1,l2,carry)
    return digit
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    return add(l1,l2,0)
}
