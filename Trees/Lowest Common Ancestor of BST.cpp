/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// LeetCode 235: Lowest Common Ancestor of a Binary Search Tree

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode* temp = root;

        // Dono nodes ko BST ki properties use karke search karna
        while (temp != nullptr)
        {
            // Agar dono nodes current root se choti hain
            // toh left subtree mein search karna
            if (temp->val > p->val && temp->val > q->val)
            {
                temp = temp->left;
            }

            // Agar dono nodes current root se bari hain
            // toh right subtree mein search karna
            else if (temp->val < p->val && temp->val < q->val)
            {
                temp = temp->right;
            }

            // Agar dono nodes alag sides par hain
            // ya current root khud p ya q hai
            // toh current node hi Lowest Common Ancestor hai
            else
            {
                return temp;
            }
        }

        return nullptr;
    }
};
