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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(-101);
        ListNode* curr=dummy;
        while(head){
            if(head->val!=curr->val){
                curr->next=new ListNode(head->val);
                head=head->next;
                curr=curr->next;
            }
            else{
                head=head->next;
            }
        }
        return dummy->next;
    }
};