class Solution {
public:
    set<int>s;
    
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return 0;
        
        int t=k-(root->val);
        if(s.find(t)!=s.end())
            return 1;
        s.insert(root->val);
        return findTarget(root->left,k)+findTarget(root->right,k);
    }
};