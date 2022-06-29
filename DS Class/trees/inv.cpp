/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* solve(Tree* root) {
    if(root==NULL)
        return NULL;

    Tree* buffer = root->left;
    root->left = solve(root->right);
    root->right= solve(buffer);
    return root;
}