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
void inorder(TreeNode* root, vector<int>& nodes)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, nodes);

        nodes.push_back(root->val);

        inorder(root->right, nodes);
    }
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;

        vector<int> nums;
        inorder(root, nums);

        for (int i = 1; i < nums.size(); i++)
        {
            int currentMin = nums[i] - nums[i - 1];

            minDiff = min(minDiff, currentMin);
        }

        return minDiff;

    }
};
