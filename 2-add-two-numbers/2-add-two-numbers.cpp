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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* head;
        ListNode* temp;
        head = l3;
        int carry=0, sum;
        while(l1 != NULL && l2 != NULL){
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            temp = new ListNode();
            temp->val = sum;
            l3->next = temp;
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1 == NULL){
            while(l2 != NULL){
                sum = l2->val + carry;
                carry = sum/10;
                sum = sum%10;
                temp = new ListNode();
                temp -> val = sum;
                l3->next = temp;
                l3 = l3->next;
                l2 = l2->next;
            }
        }else if(l2 == NULL){
            while(l1 != NULL){
                sum = l1->val + carry;
                carry = sum/10;
                sum = sum%10;
                temp = new ListNode();
                temp -> val = sum;
                l3->next = temp;
                l3 = l3->next;
                l1 = l1->next;
            }
        }
        if(carry != 0){
            temp = new ListNode();
            temp->val = carry;
            l3->next = temp;
            l3 = l3->next;
        }
        return head->next;
    }
};