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
       if(head==NULL)return NULL;
       
       Node* temp=head;
       unordered_map<Node*,Node*>mp;
       while(temp){
          Node* newnode=new Node(temp->val);
          mp[temp]=newnode;
          temp=temp->next;
       }
       temp=head;
       Node* curr=mp[temp];
       Node* ans=curr;
       while(temp){
          curr->next=mp[temp->next];
          curr->random=mp[temp->random];
          curr=curr->next;
          temp=temp->next;

       }
       return ans;
    }
};