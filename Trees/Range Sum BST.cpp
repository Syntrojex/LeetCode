class Solution
{
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        // Agar node NULL hai toh sum 0 hoga
        if (root == NULL)
        {
            return 0;
        }

        // Agar current value low se choti hai
        // toh left side ki values bhi choti hongi
        // is liye sirf right subtree check karo
        if (root->val < low)
        {
            return rangeSumBST(root->right, low, high);
        }

        // Agar current value high se bari hai
        // toh right side ki values bhi bari hongi
        // is liye sirf left subtree check karo
        else if (root->val > high)
        {
            return rangeSumBST(root->left, low, high);
        }

        // Current value range ke andar hai
        // is liye current value + left subtree ka sum + right subtree ka sum
        return root->val
             + rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
};
