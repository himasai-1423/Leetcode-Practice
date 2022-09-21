/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode ptrA=headA, ptrB=headB;
        if(ptrA == null || ptrB == null) return null;
    
        while(ptrA != ptrB){
            if(ptrA == null) ptrA = headB;
            else ptrA = ptrA.next;
            
            if(ptrB == null) ptrB = headA;
            else ptrB=ptrB.next;
        }
        return ptrA;
    }
}