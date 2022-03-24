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
    
    vector<TreeNode*> f(int lo, int hi) {
        if(hi==lo){
            TreeNode* temp = new TreeNode(lo);
            return {temp};
        }
        
        vector<TreeNode*>v1,v2,ans;
        for(int i = lo ; i<=hi ; ++i){
            if(i==lo){
                v2=f(lo+1,hi);
                for(auto x:v2){
                    TreeNode* head = new TreeNode(i);
                    head->right=x;
                    ans.push_back(head);
                }
            }
            else if(i==hi){
                v1=f(lo,hi-1);
                for(auto x:v1){
                    TreeNode* head = new TreeNode(i);
                    head->left=x;
                    ans.push_back(head);
                }
            }
            else{
                v1=f(lo,i-1);
                v2=f(i+1,hi);
                vector<TreeNode*>temp;
                for(auto x:v1){
                    TreeNode* head = new TreeNode(i);
                    head->left=x;
                    temp.push_back(head);
                }
                for(auto y:temp){
                    for(auto z:v2){
                        
                        TreeNode * a = new TreeNode(y->val,y->left,NULL);
                        a->right=z;                                                
                        ans.push_back(a);
                    }
                }
            }        
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return f(1,n);    
    }
};