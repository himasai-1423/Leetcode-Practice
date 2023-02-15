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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* travPrev = dummy, *curr=head;
        
        while(curr){
            if(curr->next && curr->val == curr->next->val){
                while(curr->next && curr->val==curr->next->val)
                    curr = curr->next;
                
                travPrev->next = curr->next;
            }
                
            
            else{
                travPrev = travPrev->next;
            }
            curr = curr->next;
        }
        
        return dummy->next;
    }
};