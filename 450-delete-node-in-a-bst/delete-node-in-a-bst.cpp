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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return root;
        if(root->val>key){
             root->left=deleteNode(root->left,key);
        }
        if(root->val<key){
             root->right=deleteNode(root->right,key);
        }
        if(root->val==key){
             if(!root->left){
                TreeNode* temp=root->right;
                delete root;
                return temp;
             }
             if(!root->right){
                TreeNode* temp=root->left;
                delete root;
                return temp;
             }
             TreeNode* succ=root->right;
             while(succ->left){
               succ=succ->left;
             }
             root->val=succ->val;
             root->right=deleteNode(root->right,root->val);
        }
        return root;
    }

};