/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void inorder(TreeNode* root, string &s){
        if(root==NULL){
            s+='#';
            return;
        }
        s+=to_string(root->val);
        s+='E';
        inorder(root->left,s);
        
        inorder(root->right,s);

    }
    string serialize(TreeNode* root) {
        string s="";
        inorder(root,s);
        return s;
    }
        TreeNode* f(string s,int &i){
            if(s[i]=='#'){
               i++;
               return NULL;
            }
            string num="";
            while(i<s.size()&&s[i]!='E'){
                  num+=s[i];
                  i++;
            }
            i++;
            TreeNode* root=new TreeNode(stoi(num));
            root->left=f(s,i);
            root->right=f(s,i);
            return root;
        }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ind=0;
        TreeNode* root=f(data,ind);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));