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
    ListNode *temp;
    bool isPalindrome(ListNode* head) {
        // vector<int> list;
        // ListNode *temp = head;
        // while(temp != NULL){
        //     list.push_back(temp->val);
        //     temp = temp->next;
        // }
        // ListNode *l3 = NULL;
        // ListNode *h = l3;
        // for(auto it = list.rbegin(); it != list.rend(); it++){
        //     ListNode *t = new ListNode(*it);
        //     if(h == NULL){
        //         h = t;
        //     } else{
        //         temp = h;
        //         while(temp->next != NULL){
        //             temp = temp->next;
        //         }
        //         temp->next = t;
        //     }
        // }
        // bool flag = true;
        // while(h != NULL && head != NULL){
        //     if(h->val != head->val){
        //         flag = false;
        //         break;
        //     }
        //     h = h->next;
        //     head = head->next;
        // }
        // return flag;
        
        temp = head;
        return pal(head);
    }
    bool pal(ListNode *p){
        if(p == NULL){
            return true;
        }
        bool flag = pal(p->next) && (temp->val == p->val);
        temp = temp->next;
        return flag;
    }
};