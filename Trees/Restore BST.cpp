class Solution
{
public:
    // Inorder traversal karke tamam nodes vector mein store karna
    void inorder(TreeNode* root, vector<TreeNode*>& nodes)
    {
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left, nodes);

        // Original tree ke node ka pointer store karna
        nodes.push_back(root);

        inorder(root->right, nodes);
    }

    void recoverTree(TreeNode* root)
    {
        vector<TreeNode*> nodes;

        // Pura tree inorder traverse karna
        inorder(root, nodes);

        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        // Har node ko uske agle node ke saath compare karna
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            // Agar pehle node ki value agle node se bari hai
            if (nodes[i]->val > nodes[i + 1]->val)
            {
                // Pehli bari galat order milne par pehla node save karna
                if (first == nullptr)
                {
                    first = nodes[i];
                }

                // Galat order wala doosra node save karna
                second = nodes[i + 1];
            }
        }

        // Dono nodes ki values aapas mein swap karna
        swap(first->val, second->val);
    }
};
