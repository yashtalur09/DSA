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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp1=NULL;
        ListNode* cur=head;
        
        while(cur!=NULL){
            ListNode* temp2=cur->next;
            cur->next=temp1;
            temp1=cur;
            cur=temp2;
        }
        return temp1;
    }
};