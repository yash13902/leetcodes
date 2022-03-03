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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = head;
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            if(head->val == val){
                head = NULL;
                return head;
            }
            else{
                return head;
            }
        }
        ListNode *node = head->next;
        while(node && node->next){
            if(node->val == val){
                prev->next = node->next;
                node = node->next;
            }else{
                prev = prev->next;
                node = node->next;
            }
        }
        node = head;
        node = head->next;
        prev = head;
        while(node->next != NULL){
            node = node->next;
            prev = prev->next;
        }
        if(node->val == val){
            prev->next = NULL;
        }
        if(head->val == val){
            head = head->next;
        }
        return head;
        
    }
};