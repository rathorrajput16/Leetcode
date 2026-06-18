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
 int ans=0;
    struct Nodevalue{
      int minnode;
      int maxnode;
      int maxsum;
      Nodevalue(int mini,int maxi,int s){
         minnode=mini;
         maxnode=maxi;
         maxsum=s;
      }
    };
     Nodevalue* helper(TreeNode* root){
        if(!root) return new Nodevalue(INT_MAX,INT_MIN,0);
        auto left=helper(root->left);
        auto right=helper(root->right);
        if(left->maxnode<root->val&&root->val<right->minnode){
            int currsum=left->maxsum+right->maxsum+root->val;
             ans=max(ans,currsum);
             return new Nodevalue(min(root->val,left->minnode),max(root->val,right->maxnode),currsum);
        }
       return new Nodevalue(
            INT_MIN,
            INT_MAX,
            0
        );
     }
    int maxSumBST(TreeNode* root) {
        if(root==NULL)return 0;
         helper(root);
        return ans;

    }
};