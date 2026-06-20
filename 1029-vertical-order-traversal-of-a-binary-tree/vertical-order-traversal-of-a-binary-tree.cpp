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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<ll,map<ll,multiset<ll>>>mp;
        queue<pair<ll,pair<ll,TreeNode*>>>q;
        q.push({0,{0,root}});
        while(!q.empty()){
            auto it=q.front();
            mp[it.first][it.second.first].insert(it.second.second->val);
            q.pop();
            if(it.second.second->left){
                q.push({it.first-1,{it.second.first+1,it.second.second->left}});
            }
            if(it.second.second->right){
                q.push({it.first+1,{it.second.first+1,it.second.second->right}});
            }
        }
        vector<vector<int>>ans;
         for(auto it:mp){
            vector<int>col;
            for(auto row:it.second){
                for(auto val : row.second){
            col.push_back(val);
        }
            }
            ans.push_back(col);
         }
         return ans;
    }
};