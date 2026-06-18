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
class Solution {
public:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;
    TreeNode* middle;
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        if(prev!=NULL&&prev->val>root->val){
            if(first==NULL){
                first=prev;
                middle=root;
            }
            else{
                second=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev=first=middle=second=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
       if(!second){
        int val=first->val;
        first->val=middle->val;
        middle->val=val;
       }
       else{
        int val=first->val;
        first->val=second->val;
        second->val=val;
       }
    }
};