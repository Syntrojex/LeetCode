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
    TreeNode* minNode(TreeNode* temp) {
        while (temp->left != NULL) {
            temp = temp->left;
        }

        return temp;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }

        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Case-1: Leaf Node
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case-2: Left Chuld
            if (root->left != NULL && root->right == NULL) {
                TreeNode* temp1 = root->left;
                delete root;
                return temp1;
            }

            // Case-3: Right Chuld
            if (root->left == NULL && root->right != NULL) {
                TreeNode* temp1 = root->right;
                delete root;
                return temp1;
            }

            // Case-4: Both child exits
            if (root->left != NULL && root->right != NULL) {
                TreeNode* succ = minNode(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }

        return root;
    }
};
