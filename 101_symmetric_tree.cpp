class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> left, right;
        if(root->left)
            left.push(root->left);
        if(root->right)
            right.push(root->right);
        while(left.size()==right.size() && !left.empty()) {
            TreeNode* l=left.front(), *r=right.front();
            left.pop();
            right.pop();
            swap(r->left, r->right);
            if((l->val!=r->val) || (l->left && r->left==NULL) || (l->left==NULL && r->left) || (r->right==NULL && l->right) || (r->right && l->right==NULL))
                return false;
            if(l->left && r->left)  {
                left.push(l->left);
                right.push(r->left);
            }
            if(l->right && r->right) {
                left.push(l->right);
                right.push(r->right);
            }
        }
        return left.empty() && right.empty();
    }
};
