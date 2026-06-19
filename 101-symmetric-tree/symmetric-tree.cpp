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
   bool helper(TreeNode* p,TreeNode* q){
    if(p==NULL&&q!=NULL)return false;
        if(p!=NULL&&q==NULL)return false;
        if(!p&&!q)return true;
        if(p->val!=q->val)return false;
    return helper(p->left,q->right)&&helper(p->right,q->left);
   }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        if(!root->left&&root->right)return false;
        if(root->left&&!root->right)return false;
        if(!root->left&&!root->right)return true;
        if(root->left->val!=root->right->val)return false;
        return helper(root->left,root->right);
    }
};