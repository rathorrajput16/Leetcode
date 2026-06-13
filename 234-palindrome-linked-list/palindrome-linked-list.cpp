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
    ListNode* reverse(ListNode* head){
         if(!head||!head->next)return head;
         ListNode* curr=head;
         ListNode* prev=NULL;
         while(curr){
            
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            
            curr=temp;
         }
         return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       ListNode* temp= reverse(slow->next);
        while(temp!=NULL){
            if(temp->val!=head->val)return false;
            head=head->next;
            temp=temp->next;
        }
        return true;
        
    }
};