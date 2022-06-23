/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        
        if(root->val == p->val || root->val == q->val) return root;
        TreeNode *lca1 = lowestCommonAncestor(root->left,  p, q);
        TreeNode *lca2 = lowestCommonAncestor(root->right,  p, q);
        
        if(lca1 && lca2) return root;
        return lca1 ? lca1 : lca2;
    }
    
    /*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> path1;
        if(!buildPath(root, p->val, path1))
            return nullptr;
        
        vector<int> path2;
        if(!buildPath(root, q->val, path2))
            return nullptr;
        
        int i;
        for(i = 0; i + 1 < path1.size() && i + 1 < path2.size(); i++) 
            if(path1[i+1] != path2[i+1])
                break;
            
        return new TreeNode(path1[i]);
    }
    
    bool buildPath(TreeNode *root, int val,  vector<int> &path) {
        if(!root) return false;
        
        path.push_back(root->val);
        if(root->val == val)
            return true;
        
        if(buildPath(root->left, val, path) || buildPath(root->right, val, path))
            return true;
        
        path.pop_back();
        return false;
    }
    */
};