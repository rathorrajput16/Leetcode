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
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*,pair<ll,ll>>>q;

        if(root==NULL)return {};
        q.push({root,{0,0}});
        while(!q.empty()){
          int s=q.size();
          while(s--){
            auto it=q.front();
            q.pop();
            mp[it.second.first][it.second.second].insert(it.first->val);
            if(it.first->left){
                  q.push({it.first->left,{it.second.first-1,it.second.second+1}});
            }
            if(it.first->right){
                 q.push({it.first->right,{it.second.first+1,it.second.second+1}});
            }
          }
          
        }
         vector<vector<int>>res;
       for (auto it : mp) {
        vector<int> col;

        for (auto row : it.second) {
            for (auto val : row.second) {
            col.push_back(val);
        }
    }

    res.push_back(col);
       }
       return res;


       
    }
    
};