/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    int carry = 0;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(not l1 and not l2 and not this->carry) return nullptr;
        int tmp = 0;
        if(l1){ 
            tmp += l1->val;
            l1 = l1->next;
        }
        if(l2){ 
            tmp += l2->val;
            l2 = l2->next;    
        }
        tmp += this->carry;
        if(tmp > 9) this->carry = 1;
        else this->carry = 0;
        ListNode* node = new ListNode(tmp%10);
        node->next = this->addTwoNumbers(l1,l2);
        return node;
    }
};
