class Node{
public:
int value;
int key;
Node* next;
Node* prev;
Node(int k,int val){
key=k;
value=val;

next=NULL;
prev=NULL;
}
};
class LRUCache {
public:
     int maxs;
     
     unordered_map<int,Node*>mp;
     Node* head=new Node(-1,-1);
     Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        maxs=capacity;
        tail->prev=head;
        head->next=tail;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
                 Node* temp=mp[key];
                 mp.erase(key);
                   Node* back=temp->prev;
                   Node* after=temp->next;
                   back->next=after;
                   after->prev=back;
                   Node* newnode=new Node(key,temp->value);
                   temp=tail->prev;
                   temp->next=newnode;
                   newnode->prev=temp;
                   newnode->next=tail;
                   tail->prev=newnode;
                 mp[key]=newnode;
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
                 mp.erase(key);
                   Node* back=temp->prev;
                   Node* after=temp->next;
                   back->next=after;
                   after->prev=back;
                   Node* newnode=new Node(key,value);
                   temp=tail->prev;
                   temp->next=newnode;
                   newnode->prev=temp;
                   newnode->next=tail;
                   tail->prev=newnode;
                 mp[key]=newnode;
        }
        else{
            if(mp.size()==maxs){
              Node* temp=head->next;
              head->next=temp->next;
              temp->next->prev=head;
              mp.erase(temp->key);
              delete temp;
            }
            Node* newnode=new Node(key,value);
                   Node* temp=tail->prev;
                   temp->next=newnode;
                   newnode->prev=temp;
                   newnode->next=tail;
                   tail->prev=newnode;
                 mp[key]=newnode;

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */