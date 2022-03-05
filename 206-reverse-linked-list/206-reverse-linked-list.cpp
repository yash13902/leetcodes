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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        vector<int> list;
        ListNode* temp = head;
        while(temp != NULL){
            list.insert(list.end(), temp->val);
            temp = temp->next;
        }
        temp = head;
        for(auto it = list.rbegin(); it != list.rend(); it++){
            head->val = *it;
            head = head->next;
        }   
        return temp;
    }
};