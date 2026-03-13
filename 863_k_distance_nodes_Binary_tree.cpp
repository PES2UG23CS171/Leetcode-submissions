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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        if(root==NULL || target==NULL)
            return {};
        unordered_map<int,vector<int>> hash;
        queue<TreeNode*> next;
        next.push(root);
        while(!next.empty())
        {
            TreeNode* temp=next.front();
            next.pop();
            if(temp->left)
            {
                hash[temp->val].push_back(temp->left->val);
                hash[temp->left->val].push_back(temp->val);
                next.push(temp->left);
            }
            if(temp->right)
            {
                hash[temp->val].push_back(temp->right->val);
                hash[temp->right->val].push_back(temp->val);
                next.push(temp->right);
            }
        }
        queue<int> NN;
        NN.push(target->val);
        int dist=0;
        unordered_set<int> seen;
        seen.insert(target->val);
        while(dist!=k)
        {
            dist++;
            int s=NN.size();
            while(s--)
            {
                int c=NN.front();
                NN.pop();
                for(int i: hash[c])
                {
                    if(seen.find(i)==seen.end())
                    {
                        seen.insert(i);
                        NN.push(i);
                    }
                }
            }
        }
        vector<int> ans;
        while(!NN.empty())
        {
            ans.push_back(NN.front());
            NN.pop();
        }
        return ans;
    }
};
