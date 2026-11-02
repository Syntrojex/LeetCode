class Solution
{
public:
    // Inorder traversal karke tamam nodes ko sorted order mein store karna
    void inorder(TreeNode* root, vector<TreeNode*>& nodes)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, nodes);

        // Original node ka pointer vector mein store karna
        nodes.push_back(root);

        inorder(root->right, nodes);
    }

    // Sorted nodes se recursively balanced BST banana
    TreeNode* build(vector<TreeNode*>& nodes, int left, int right)
    {
        // Agar is range mein koi node nahi bacha
        if (left > right)
        {
            return nullptr;
        }

        // Current range ka middle index nikalna
        int mid = left + (right - left) / 2;

        // Middle node ko current subtree ka root banana
        TreeNode* root = nodes[mid];

        // Middle se pehle wale nodes se left subtree banana
        root->left = build(nodes, left, mid - 1);

        // Middle ke baad wale nodes se right subtree banana
        root->right = build(nodes, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root)
    {
        vector<TreeNode*> nodes;

        // Pura BST inorder traverse karke sorted nodes collect karna
        inorder(root, nodes);

        // Vector ki starting aur ending index set karna
        int left = 0;
        int right = nodes.size() - 1;

        // Sorted nodes se balanced BST construct karna
        root = build(nodes, left, right);

        return root;
    }
};
