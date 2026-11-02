class Solution
{
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

    int minDiffInBST(TreeNode* root)
    {
        int minDistance = INT_MAX;

        vector<int> nums;
        inorder(root, nums);

        for (int i = 1; i < nums.size(); i++)
        {
            int currentMin = nums[i] - nums[i - 1];

            minDistance = min(minDistance, currentMin);
        }

        return minDistance;
    }
};
