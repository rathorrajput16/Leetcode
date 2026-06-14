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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=new ListNode(-1);
        ListNode* l=l3;
        int sum=0;
        int carry=0;
        while(l1!=NULL&&l2!=NULL){
          sum=l1->val+l2->val+carry;
          l1=l1->next;
          l2=l2->next;
          if(sum>=10){
            carry=1;
            l->next=new ListNode(sum%10);
            l=l->next;
          }         
          else{
            carry=0;
            l->next=new ListNode(sum%10);
            l=l->next;
          } 
        }
        while(l1!=NULL){
            sum=l1->val+carry;
          l1=l1->next;
          if(sum>=10){
            carry=1;
            l->next=new ListNode(sum%10);
            l=l->next;
          }         
          else{
            carry=0;
            l->next=new ListNode(sum%10);
            l=l->next;
          } 
        }
        while(l2!=NULL){
            sum=l2->val+carry;
          l2=l2->next;
          if(sum>=10){
            carry=1;
            l->next=new ListNode(sum%10);
            l=l->next;
          }         
          else{
            carry=0;
            l->next=new ListNode(sum%10);
            l=l->next;
          } 
        }
      


        if(carry!=0){
             l->next=new ListNode(carry);
            l=l->next;
        }

        return  l3->next; 
    }
};