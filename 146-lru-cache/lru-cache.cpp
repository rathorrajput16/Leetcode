class LRUCache {
public:

    struct Node{
       Node* next;
       Node* prev;
       int key;
       int val;
       Node(int k,int v){
          key=k;
          val=v;
          next=NULL;
          prev=NULL;
       }
       Node(){
         next=NULL;
          prev=NULL;
       }
    };
     Node* head;
    Node* tail;
    void remove(Node* node){
        Node* back=node->prev;
        Node* front=node->next;
        back->next=front;
        front->prev=back;
        
    }
    void add(Node* node){
        Node* back=tail->prev;
        back->next=node;
        tail->prev=node;
        node->next=tail;
        node->prev=back;
    }
    int size;
    int maxsize;
    unordered_map<int,Node*>mp;
   
    LRUCache(int capacity) {
        maxsize=capacity;
        size=0;
         head = new Node();
        tail = new Node();

        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
               Node* newnode=mp[key];
               mp.erase(key);
               remove(newnode);
               add(newnode);
               mp[key]=newnode;
               return newnode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
         if(mp.find(key)!=mp.end()){
               Node* newnode=mp[key];
               mp.erase(key);
               remove(newnode);
               add(newnode);
               mp[key]=newnode;
               newnode->val = value;
               return;
        }
        if(maxsize==size){
            int k=head->next->key;
            mp.erase(k);
            Node* lr=head->next;
            remove(head->next);
            size--;
            delete(lr);
        }
         Node* newnode=new Node(key,value);
               add(newnode);
               mp[key]=newnode;
               size++;
       
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */