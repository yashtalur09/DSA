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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL) return {-1,-1};
        ListNode* cur=head->next;
        ListNode* prev=head;
        
        if(cur==NULL) return {-1,-1};
        int ind=2;
        vector<int> index;
        while(cur!=NULL){
            ListNode* next=cur->next;
            if (prev != NULL && next != NULL) {
                if ((cur->val < prev->val && cur->val < next->val) ||
                    (cur->val > prev->val && cur->val > next->val)) {
                    index.push_back(ind);
                }
            }
            ind++;
            prev=cur;
            cur=cur->next;
            
        }
        int n=index.size();
        if(n<2){
            return {-1,-1};
        }
        int maxi=abs(index.front()-index.back());
        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            mini=min(mini,abs(index[i]-index[i-1]));
        }
        return {mini,maxi};
    }
};