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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        
        ListNode* slow = head, *fast = head;
        
        do {
            if(!fast || !fast->next) return NULL;
            
            fast = fast->next->next;
            slow = slow->next;
        } while(fast!=slow);
        
        ListNode* slowChk = head;
        while(slowChk!=slow) {
            slow = slow->next;
            slowChk = slowChk->next;
        } 
        
        return slow;
    }
};