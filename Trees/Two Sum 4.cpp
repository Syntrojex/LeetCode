class Solution {
public:
    // Pass nums by reference (&) taake copies na banen or usi array me kam ho
    void inorderTraversal(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) {
            return;
        }

        inorderTraversal(root->left, nums);
        nums.push_back(root->val);
        inorderTraversal(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorderTraversal(root, nums);

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                return true;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }
        return false;
    }
};
