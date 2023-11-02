// Author  :   Vicen-te
// Date    :   11/02/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      Given the root of a binary tree, return the number of nodes where the value of the node is
 *       equal to the average of the values in its subtree.
 * 
 *      Note:
 *          The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
 *          A subtree of root is a tree consisting of root and all of its descendants.
 * 
 *      Each non-leaf node's value should be equal to the product of the values of its children.
 * 
 *      Return the number of binary trees we can make. 
 *      The answer may be too large so return the answer modulo 109 + 7.
 *  
 *      Ex1.
 *          Input: root = [4,8,5,0,1,null,6]
 *          Output: 5
 *          Explanation: 
 *              For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
 *              For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
 *              For the node with value 0: The average of its subtree is 0 / 1 = 0.
 *              For the node with value 1: The average of its subtree is 1 / 1 = 1.
 *              For the node with value 6: The average of its subtree is 6 / 1 = 6.
 * 
 *  Algorithm:
 * 
 *      Time: O(N)
 *      Space: O(N)
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
    std::pair<int, int> postOrden(TreeNode* root, int& res)
    {
        if(root == nullptr) return {0, 0};
        
        std::pair<int, int> right = postOrden(root->left, res);
        std::pair<int, int> left = postOrden(root->right, res);
        
        int num_of_nodes = right.first + left.first + 1;
        int sum = right.second + left.second + root->val;

        if(sum/num_of_nodes == root->val) ++res;
        return {num_of_nodes, sum};
    }

    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        postOrden(root, res);
        return res;
    }
};