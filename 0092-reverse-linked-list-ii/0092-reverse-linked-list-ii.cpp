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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = head, * leftPrev = dummy;
        
        for(int i=0; i<left-1; i++){
            leftPrev = curr;
            curr = curr->next;
        }
        
        ListNode *prev = NULL;
        for(int i=0; i<=right-left; i++){
            ListNode *nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        
        leftPrev->next->next = curr;
        leftPrev->next = prev;
        
        return dummy->next;
    }
};