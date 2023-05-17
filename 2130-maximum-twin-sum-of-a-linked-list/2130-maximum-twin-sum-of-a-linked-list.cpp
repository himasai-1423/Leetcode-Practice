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
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = NULL, *nextPtr = NULL;
        
        //Reversing a Linked List 
        while(slow) {
            nextPtr = slow->next;
            slow->next = prev;
            
            prev = slow;
            slow = nextPtr;
        }
        
        int res = 0;
        while(prev) {
            res = max(res, prev->val + head->val);
            prev = prev->next;
            head = head->next;
        }
        
        return res;
    }
};