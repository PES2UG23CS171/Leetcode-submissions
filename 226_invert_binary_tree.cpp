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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        queue<TreeNode*> next;
        next.push(root);
        while(!next.empty()) {
            TreeNode* curr=next.front();
            TreeNode* temp=curr->right;
            curr->right=curr->left;
            curr->left=temp;
            if(curr->right)
                next.push(curr->right);
            if(curr->left)
                next.push(curr->left);
            next.pop();
        }
        return root;
    }
};
