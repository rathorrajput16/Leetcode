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
    using ll=long long;
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,1});
        ll ans=0;
        
        while(!q.empty()){
            ll s=q.size();
            ll mini=1e9;
            ll maxi=-1e9;
            ll last=q.front().second;
            while(s--){
                auto it=q.front();
                q.pop();
                it.second=it.second-last;
                mini=min(mini,it.second);
                if(it.first->left){
                    q.push({it.first->left,2*it.second});
                }
                maxi=max(maxi,it.second);
                if(it.first->right){
                    q.push({it.first->right,2*it.second+1});
                }
            }
             ans=max(ans,maxi-mini+1);


        }
        return ans;
    }
};