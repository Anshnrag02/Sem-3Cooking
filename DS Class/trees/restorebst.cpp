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
    void solver(TreeNode * root){
        if(root==NULL or a!=NULL){
            return;
        }
        
        solver(root->left);
        
        if(prev->val>root->val){
            a=prev;
            return;
        }
        
        prev=root;
        solver(root->right);
    }
    
    void rsolver(TreeNode * root){
        
        if(root==NULL or b!=NULL){
            return;
        }
        
        rsolver(root->right);
        
        if(prev->val<root->val){
            b=prev;
            return;
        }
        
        prev=root;
        rsolver(root->left);
    }
    
    
    TreeNode *prev;
    TreeNode *a=NULL;
    TreeNode *b=NULL;
    
    
    void recoverTree(TreeNode* root) {
        
        prev=new TreeNode(INT_MIN);
        
        solver(root);
        
        prev=new TreeNode(INT_MAX);
        
        rsolver(root);

        swap(a->val,b->val);
    }
};