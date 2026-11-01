class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        queue<TreeNode*> q1;

        if (root == NULL)
        {
            return result;
        }

        q1.push(root);

        while (!q1.empty())
        {
            int levelSize = q1.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++)
            {
                TreeNode* current = q1.front();
                q1.pop();

                currentLevel.push_back(current->val);

                if (current->left != NULL)
                {
                    q1.push(current->left);
                }

                if (current->right != NULL)
                {
                    q1.push(current->right);
                }
            }

            result.push_back(currentLevel);
        }

        return result;
    }
};
