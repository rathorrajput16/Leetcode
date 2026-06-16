class Node{
public:
string link;
Node* next;
Node* prev;
Node(string s){
    link=s;
    next=NULL;
    prev=NULL;
}
};
class BrowserHistory {
public:
    Node* dummy=new Node("ayush");
    Node* curr=dummy;
    BrowserHistory(string homepage) {
        curr->next=new Node(homepage);
        
        curr=curr->next;
    }
    
    void visit(string url) {
        curr->next=new Node(url);
        curr->next->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(steps>0&&curr!=dummy->next){
          curr=curr->prev;
          steps--;
        }
        return curr->link;
    }
    
    string forward(int steps) {
        while(steps>0&&curr->next!=NULL){
          curr=curr->next;
          steps--;
        }
        return curr->link;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */