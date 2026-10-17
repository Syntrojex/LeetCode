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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<int> result;
        result.push_back(root->val);

        vector<int> left_part = preorderTraversal(root->left);
        result.insert(result.end(), left_part.begin(), left_part.end());

        vector<int> right_part = preorderTraversal(root->right);
        result.insert(result.end(), right_part.begin(), right_part.end());

        return result;
    }
};

/*
Approach:

- Agar root NULL ho, to empty vector return kar do.
- Sabse pehle root ki value result vector mein add karo.
- Left subtree ka preorder traversal karke uska result left_part mein lo.
- insert() se left_part ke tamam elements ko result ke end mein append kar do.
- Phir right subtree ka preorder traversal karke uska result right_part mein lo.
- right_part ke tamam elements ko bhi result ke end mein append kar do.
- Aakhir mein complete result vector return kar do.

Traversal Order:
Root -> Left -> Right

Time Complexity: O(n) traversal ke liye, lekin vectors ko baar baar
copy aur append karne ki wajah se worst case O(n^2) ho sakti hai.

Space Complexity: O(n) result vectors aur recursion stack ke liye.
*/
