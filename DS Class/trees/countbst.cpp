/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int ans;

void dfs(Tree * root, int lo ,int hi){
    if(root==NULL)
        return;
    if(root->val>=lo and root->val<=hi){
        ans++;
        dfs(root->left, lo,hi);
        dfs(root->right,lo,hi);
}
    if(root->val<lo)
        dfs(root->right,lo,hi);
    
    if(root->val>hi)
        dfs(root->left,lo,hi);

}


int solve(Tree* root, int lo, int hi) {
    ans=0;
    dfs(root,lo,hi);
    return ans;
}