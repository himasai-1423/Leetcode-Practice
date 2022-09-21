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
        ListNode *next=NULL, *curr = head;
        
        while(curr != NULL){
            next = curr->next;
            if( curr->next != NULL && curr->val == next->val){
                curr->next = curr->next->next;
                delete next;
                continue;
            }
            if(curr->next == NULL) break;
            curr=curr->next;
        }
        return head;
    }
};