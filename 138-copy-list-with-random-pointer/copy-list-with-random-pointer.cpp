/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        if(head==NULL)return head;
        while(curr){
            Node* newnode=new Node(curr->val);
            Node* temp=curr->next;
            newnode->next=temp;
            curr->next=newnode;
            curr=temp;
        }
        curr=head;
        while(curr){
            Node* temp=curr->next;
            Node* point=curr->random;
            if(point!=NULL){
                temp->random=point->next;
            }
            curr=temp->next;
        }
        Node* ans=head->next;
        curr=head;
        while(curr){
           Node* temp=curr;
           Node* temp2=curr->next;
           temp->next=temp2->next;
           if(temp2->next!=NULL){
            temp2->next=temp2->next->next;
           }
           curr=temp->next;
        }
       
        
        return ans;
    }
};