// Same Concept as LeetCode 1382: Balance a Binary Search Tree

class Solution
{
public:
    TreeNode* build(vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        int mid = (left + right) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        TreeNode* root = build(nums, left, right);

        return root;
    }
};
