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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        ListNode* prev = NULL;
        
        if(!head->next) return NULL;
        
        while(fastptr->next && fastptr->next->next){
            fastptr=fastptr->next->next;
            prev = slowptr;
            slowptr= slowptr->next;
        }
        
        if(fastptr->next){
            prev=slowptr;
            slowptr=slowptr->next;
        }
        
        prev->next = slowptr->next;
        delete(slowptr);
        
        return head;
    }
};