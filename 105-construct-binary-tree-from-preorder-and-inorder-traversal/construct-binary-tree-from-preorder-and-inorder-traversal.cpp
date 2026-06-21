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
    unordered_map<int,int>mp;
    TreeNode* f(int prestart,int preend,int instart,int inend,vector<int>& preorder, vector<int>& inorder){
          if(prestart>preend||instart>inend){
            return NULL;
          }
          int ind=mp[preorder[prestart]];
          int size=ind-instart;
          TreeNode* root=new TreeNode(preorder[prestart]);
          root->left=f(prestart+1,prestart+size,instart,ind-1,preorder,inorder);
          root->right=f(prestart+size+1,preend,ind+1,inend,preorder,inorder);
          return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0;i<inorder.size();i++){
         mp[inorder[i]]=i;   
        }
        int n=inorder.size();
        TreeNode* root=f(0,n-1,0,n-1,preorder,inorder);
        return root;
    }
};