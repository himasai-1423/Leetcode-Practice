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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* midNode = findMid(head);

        ListNode* left = sortList(head);
        ListNode* right = sortList(midNode);
        return merge(left, right);
    }
    
    ListNode* findMid(ListNode* head){
        ListNode *midPrev = nullptr;
        
        while(head && head->next){
            midPrev = midPrev==NULL? head: midPrev->next;
            head = head->next->next;
        }
        ListNode *mid = midPrev->next;
        midPrev->next = NULL;
        return mid;
    }
    
    ListNode* merge(ListNode* left, ListNode *right){
        ListNode *dummy = new ListNode(0);
        ListNode *res = dummy;
        
        while(left && right){
            if(left->val < right->val){
                dummy->next = left;
                left = left->next;
            }
            
            else{
                dummy->next=right;
                right = right->next;
            }
            dummy = dummy->next;
        }
        
        if(left) dummy->next = left;
        else dummy->next = right;
        
        return res->next;
    }
};