/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        int n;
        ListNode list3 = new ListNode();
        ListNode head = list3;
        while(list1!=null && list2!=null){
            if(list1.val < list2.val){
                n = list1.val;
                list1 = list1.next;
            } else{
                n = list2.val;
                list2 = list2.next;
            }
            ListNode temp = new ListNode(n);
            list3.next = temp;
            list3 = list3.next;
        }
        if(list1 != null){
            while(list1 != null){
            ListNode temp = new ListNode(list1.val);
            list3.next = temp;
            list3 = list3.next;
            list1 = list1.next;
            }
        } else if(list2 != null){
            while(list2 != null){
            ListNode temp = new ListNode(list2.val);
            list3.next = temp;
            list3 = list3.next;
            list2 = list2.next;
            }
        }
        return head.next;
    }
    
}