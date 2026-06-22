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
map<int,int>mp;
   TreeNode* f(int ins,int ine,int ps,int pe,vector<int>& inorder, vector<int>& postorder){
    if(ins>ine||ps>pe)return NULL;
    TreeNode* root=new TreeNode(postorder[pe]);
    int ind=mp[postorder[pe]];
    int s=ine-ind;
    root->left=f(ins,ind-1,ps,pe-s-1,inorder,postorder);
    root->right=f(ind+1,ine,pe-s,pe-1,inorder,postorder);
    return root;
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int n=inorder.size();
        TreeNode* root=f(0,n-1,0,n-1,inorder,postorder);
        return root;

        
    }
};