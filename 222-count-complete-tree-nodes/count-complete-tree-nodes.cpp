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
    int helper(TreeNode* root){
        if(root==NULL)return 0;
        return 1+helper(root->left);
    }
    int helper1(TreeNode* root){
        if(root==NULL)return 0;
         return 1+helper1(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=helper(root);
        int rh=helper1(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
        else{
            return 1+countNodes(root->left)+countNodes(root->right);
        }
    }
};