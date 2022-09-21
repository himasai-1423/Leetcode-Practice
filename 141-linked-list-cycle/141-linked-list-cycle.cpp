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
        ListNode *fastptr = head;
        ListNode *slowptr = head;
        while(fastptr && fastptr->next){
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
            
            if(fastptr == slowptr) return true;
        }
        return false;
    }
};