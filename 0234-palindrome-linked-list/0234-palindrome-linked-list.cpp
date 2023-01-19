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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head;
        
        stack<int> st;
        st.push(head->val);
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast){
                st.push(slow->val);
                cout<<slow->val<<endl;
            }
        }     
        
        if(slow->val!=st.top())
            st.pop();
        
        while(slow && !st.empty()){
            int x = st.top();
            st.pop();
            if(slow->val == x)
                slow = slow->next;
        }
        
        if(!slow && st.empty())
            return true;
        
        return false;
    }
};