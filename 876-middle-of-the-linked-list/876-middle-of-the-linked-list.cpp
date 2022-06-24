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
    ListNode* middleNode(ListNode* head) {
        ListNode *start = head->next;
        int count=0;
        while(start != NULL){
            count++;
            start = start->next;
        }
        count++;
        cout << count;
        count /= 2;
        while(count-- != 0){
            head = head->next;
        }
        return head;
    }
};