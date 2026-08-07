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
        if(head==NULL) return NULL;
        if(head->next==NULL){
            head=NULL;
            return head;
        }
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        // if(count==2 && n==1){
        //     head->next=NULL;
        //     return head;
        // }
        // if(count==2 && n==2){
        //     head=head->next;
        //     return head;
        // }
        temp=head;
        int node=count-n;
        if(node==0){
            head=head->next;
            return head;
        }
        while(node){
            node--;
            if(node==0) break;
            temp=temp->next;
        }
        if(temp!=NULL && temp->next!=NULL)temp->next=temp->next->next;
        return head;
    }
};