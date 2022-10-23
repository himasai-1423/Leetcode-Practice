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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=1;
        ListNode* temp = head;
        
        if(!head->next) return NULL;

        while(temp->next){
            temp=temp->next;
            len++;
        }
        int req = len-n-1;
        temp=head;
        
        if(len==n) return head->next;
        
        for(int i=0; i<req; i++){
            temp=temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};