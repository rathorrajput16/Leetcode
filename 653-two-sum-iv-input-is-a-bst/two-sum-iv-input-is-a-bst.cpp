/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    void pushall(TreeNode* root){
        TreeNode* curr=root;
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
    }
    int next() {
        int val=st.top()->val;
        TreeNode* node=st.top();
        st.pop();
        pushall(node->right);
        return val;
    }
    
    bool hasNext() {
        if(!st.empty())return true;
        else return false;
    }
};
class BSTIterator2 {
public:
    stack<TreeNode*>st;
    BSTIterator2(TreeNode* root) {
        pushall(root);
    }
    void pushall(TreeNode* root){
        TreeNode* curr=root;
        while(curr){
            st.push(curr);
            curr=curr->right;
        }
    }
    int next() {
        int val=st.top()->val;
        TreeNode* node=st.top();
        st.pop();
        pushall(node->left);
        return val;
    }
    
    bool hasNext() {
        if(!st.empty())return true;
        else return false;
    }
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left=BSTIterator(root);
        BSTIterator2 right=(root);
        int i=left.next(),j=right.next();
        while(i<j){
              if(i+j==k)return true;
              else if(i+j<k)i=left.next();
              else j=right.next();
        }
        return false;
    }
};