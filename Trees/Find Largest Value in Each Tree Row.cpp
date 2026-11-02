class Solution {
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            int n = q.size();
            int maxVal = INT_MIN;

            for (int i = 0; i < n; i++) 
            {
                TreeNode* curr = q.front();
                q.pop();

                maxVal = max(maxVal, curr->val);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }

            ans.push_back(maxVal);
        }

        return ans;
    }
};
