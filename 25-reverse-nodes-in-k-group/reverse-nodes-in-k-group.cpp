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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev=NULL;
        ListNode* temp=head;
         for(int i=0;i<k;i++){
              if(!temp)return head;
                temp=temp->next;
         }
         prev=temp;
        ListNode* curr=head;
        int cnt=k;
        while(curr&&cnt>0){
            ListNode* tempo=curr->next;
            curr->next=prev;
            prev=curr;
            curr=tempo;
            cnt--;
        }

        head->next=reverseKGroup(temp,k);
        return prev;

    }
};