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
    int helper(TreeNode* root,int sum){
        if(root==NULL){
            return 0;
        }
        sum=(sum*10)+root->val;
        cout<<sum<<" "<<endl;
        if(!root->right && !root->left){
            return sum;
        }
        return helper(root->left,sum)+helper(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};