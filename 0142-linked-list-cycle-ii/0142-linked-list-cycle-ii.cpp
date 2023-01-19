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
        if(!head) return NULL;
        
        ListNode* fast = head, *slow = head;
        
        do{
            if(!fast || !fast->next) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);
        
        ListNode* slow2 = head;
        
        while(slow != slow2){
            slow = slow->next;
            slow2 = slow2->next;
        }
        return slow;
    }
};