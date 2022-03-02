/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        while(head!=NULL && head->next!=NULL ){
            head = head->next->next;
            slow = slow->next;
            if(head == slow){
                return true;
            }
        }
        return false;
    }
};