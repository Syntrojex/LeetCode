class Solution
{
public:
    void preorder(TreeNode* root, vector<TreeNode*>& nodes)
    {
        if (root == nullptr)
        {
            return;
        }

        nodes.push_back(root);

        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }

    void flatten(TreeNode* root)
    {
        vector<TreeNode*> nodes;

        preorder(root, nodes);

        if (nodes.empty())
        {
            return;
        }

        // First node ka left NULL
        nodes[0]->left = nullptr;

        // Tamam nodes ko next node se connect karna
        for (int i = 0; i < nodes.size() - 1; i++)
        {
            nodes[i]->right = nodes[i + 1];
            nodes[i + 1]->left = nullptr;
        }

        // Last node ka right NULL
        nodes[nodes.size() - 1]->right = nullptr;
    }
};
