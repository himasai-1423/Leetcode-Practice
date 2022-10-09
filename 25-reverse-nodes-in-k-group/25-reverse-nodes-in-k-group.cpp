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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next = head;
        
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        ListNode* nxt=NULL;
        
        ListNode* before = dummy;
        ListNode* after = head;
        
        while(true){
            ListNode*cursor = before;
            for(int i=0; i<k; i++){
                if(!cursor->next) return dummy->next;
                cursor=cursor->next;
            }
            
            curr = after;
            prev = before;
            
            for(int i=0; i<k; i++){
                nxt = curr->next;
                curr->next = prev;
                prev=curr;
                curr=nxt;
            }
            
            before->next=prev;
            after->next=curr;
            before=after;
            after=curr;
        }   
        return dummy->next;
    }
};