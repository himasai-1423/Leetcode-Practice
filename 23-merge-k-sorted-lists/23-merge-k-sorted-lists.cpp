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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size(); 
        
        if(k==0) return NULL;
        vector<int> datum;
        
        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp){
                datum.push_back(temp->val);
                temp=temp->next;
            }
        }
        if(datum.size()==NULL) return NULL;
        sort(datum.begin(), datum.end());
        
        int cnt=0;
        ListNode* res = new ListNode();
        ListNode* head = res;
        
        for(int &i: datum){
            res->val = i;
            cnt++;
            if(cnt!=datum.size()){
                ListNode* newNode = new ListNode();
                res->next=newNode;
                res=res->next;
            }
        }
        return head;
    }
};