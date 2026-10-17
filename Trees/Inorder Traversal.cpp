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

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root == NULL)
        {
            return {};
        }

        // 1. Left subtree ka vector mangwaya
        vector<int> result = inorderTraversal(root->left);

        // 2. 'cout' ki jagah current value ko vector mein push kiya
        result.push_back(root->val);

        // 3. Right subtree ka vector mangwaya aur use pehle wale vector mein jod (append) diya
        vector<int> right_part = inorderTraversal(root->right);
        result.insert(result.end(), right_part.begin(), right_part.end());

        // 4. Khali {} ki jagah actual result return kiya
        return result;
    }
};

/*
Approach:

1. Inorder Traversal ka order hota hai:
   Left -> Root -> Right

2. Sabse pehle root ke left subtree ko recursively traverse karte hain.
   Jo values left subtree se milti hain, unka vector 'result' mein store hota hai.

3. result.push_back(root->val):
   'push_back()' vector ke END mein ek nayi value add karta hai.
   Yahan current root ki value ko left subtree ke result ke baad add kar rahe hain.

   Example:
   Agar left subtree ka result = [1, 2]
   aur current root = 3

   push_back(3) ke baad:
   result = [1, 2, 3]

4. Phir right subtree ko recursively traverse karte hain.
   Uska result alag vector 'right_part' mein milta hai.

5. result.insert(result.end(), right_part.begin(), right_part.end()):
   'insert()' ek vector ke andar multiple elements add kar sakta hai.

   Yahan:
   - result.end() batata hai ke elements kahan se insert karne hain.
     Matlab result ke bilkul END par.
   - right_part.begin() right_part ke FIRST element ko represent karta hai.
   - right_part.end() right_part ke END ke baad wali position ko represent karta hai.

   Example:
   result = [1, 2, 3]
   right_part = [4, 5]

   insert ke baad:
   result = [1, 2, 3, 4, 5]

6. Is tarah recursion har node ke liye:
   Left -> Current Node -> Right
   ka order maintain karti hai.

7. Agar root NULL ho, toh empty vector {} return hota hai.
   Iska matlab us subtree mein koi node nahi hai.

Time Complexity: O(n)
Space Complexity: O(n)
*/
