// Author  :   Vicen-te
// Date    :   10/25/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      Given the root of a binary tree, return an array of the largest value in each row of the
 *      tree (0-indexed).
 * 
 *      Ex1.
 *          Input: root = [1,3,2,5,3,null,9]
 *          Output: [1,3,9]
 * 
 *      Ex2.
 *          Input: root = [1,2,3]
 *          Output: [1,3]
 * 
 *  Algorithm:
 *      1. Use BFS (Breadth-First Search) with a queue to traverse the binary tree.
 *      2. Progress to the next level when all nodes at the current level are explored.
 *      3. Track the maximum value within the current level.
 *      4. Add the maximum value to the result vector at the end of each level.
 *      5. Return the vector containing the maximum values after completing the tree traversal.
 * 
 *      Time: O(N)
 *      Space: O(N)
 * 
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return vector<int>();

        std::vector<int> res;
        std::queue<TreeNode*> queue;
        queue.push(root);

        while(queue.size())
        {
            int size = queue.size();
            int max_value = INT_MIN;

            while(size--)
            {
                TreeNode*& node = queue.front();
                max_value = max(max_value, node->val);
                if(node->left != nullptr) queue.push(node->left);
                if(node->right != nullptr) queue.push(node->right);
                queue.pop();
            }

            res.push_back(max_value);
        }

        return res;
    }
};