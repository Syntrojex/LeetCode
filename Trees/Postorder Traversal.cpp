/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<int> result;

        vector<int> left_part = postorderTraversal(root->left);
        result.insert(result.end(), left_part.begin(), left_part.end());

        vector<int> right_part = postorderTraversal(root->right);
        result.insert(result.end(), right_part.begin(), right_part.end());

        result.push_back(root->val);

        return result;
    }
};

/*
Approach:

- Agar root NULL ho, to empty vector return kar do.
- Sabse pehle left subtree ka postorder traversal karo.
- Left subtree ke tamam elements ko result ke end mein append kar do.
- Phir right subtree ka postorder traversal karo.
- Right subtree ke tamam elements ko bhi result ke end mein append kar do.
- Aakhir mein current root ki value result mein add karo.
- Complete result vector return kar do.

Traversal Order:
Left -> Right -> Root

Time Complexity: Worst case O(n^2), kyun ke recursive calls mein vectors
ko baar baar copy aur append kiya ja raha hai.

Space Complexity: O(n) result vectors aur recursion stack ke liye.
*/
