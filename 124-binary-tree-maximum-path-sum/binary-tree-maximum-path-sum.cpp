/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     ll val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(ll x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    using ll=long long;
public:
    ll maxi =LLONG_MIN;
     ll h(TreeNode* root){
        if(root==NULL)return 0;
        ll lh=h(root->left);
        lh=max(lh,0LL);
        ll rh=h(root->right);
        rh=max(rh,0LL);
        maxi=max(maxi,lh+rh+root->val);
        return max(lh+root->val,rh+root->val);
     }
    int maxPathSum(TreeNode* root) {
       h(root);
      return maxi;  
    }
};