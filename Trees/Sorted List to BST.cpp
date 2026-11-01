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

    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int> nums;

        ListNode* temp = head;
        while (temp != nullptr)
        {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int left = 0;
        int right = nums.size() - 1;

        TreeNode* root = build(nums, left, right);

        return root;
    }
};
