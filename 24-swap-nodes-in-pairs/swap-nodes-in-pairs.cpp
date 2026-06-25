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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        if(head==NULL||head->next==NULL)return head;
        ListNode* groupprev=dummy;
        while(true){
            ListNode* k=groupprev;
            int cnt=2;
            while(cnt>0){
               k=k->next;
               cnt--;
               if(k==NULL)return dummy->next;
            }
            ListNode* groupnext=k->next;
            ListNode* prev=k->next;
            ListNode* curr=groupprev->next;
            while(curr&&curr!=groupnext){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            ListNode* temp=groupprev->next;
            groupprev->next=k;
            groupprev=temp;
        }
        return dummy->next;
    }
};