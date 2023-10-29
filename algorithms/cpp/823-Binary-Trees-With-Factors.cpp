// Author  :   Vicen-te
// Date    :   10/29/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      Given an array of unique integers, arr, where each integer arr[i] 
 *      is strictly greater than 1.
 * 
 *      We make a binary tree using these integers, and each number may be used 
 *      for any number of times.
 * 
 *      Each non-leaf node's value should be equal to the product of the values of its children.
 * 
 *      Return the number of binary trees we can make. 
 *      The answer may be too large so return the answer modulo 109 + 7.
 *  
 *      Ex1.
 *          Input: arr = [2,4]
 *          Output: 3
 *          Explanation: We can make these trees: [2], [4], [4, 2, 2]
 * 
 *      Ex2.
 *          Input: arr = [2,4,5,10]
 *          Output: 7
 *          Explanation: 
 *              We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
 * 
 *  Algorithm:
 *      1. Sorting the array is essential to streamline divisibility checks, 
 *         ensuring that smaller potential divisors are examined first.
 * 
 *      2. Create a dynamic programming map ('dp') to keep track of the 
 *         number of binary trees that can be formed using each number in the array.
 * 
 *      3. Set all values in the 'dp' map to 1, indicating that each number can initially
 *         form its own binary tree.
 * 
 *      4. Iterate through the array to check if each number is divisible by smaller values that
 *         appear earlier in the sorted array. Divisibility implies the potential for a 
 *         non-leaf node in a binary tree.
 * 
 *      5. For each divisible number, validate whether the 
 *         other factor (the result of the division) is already present in the 'dp' map.
 * 
 *      6. If the other factor exists in the 'dp' map, increase the count of binary trees for the
 *         current number. This update is achieved by multiplying the counts of the two factors, 
 *         recognizing that each can contribute to a separate subtree. The final count represents 
 *         the total number of possible binary trees.
 *  
 *      Example:
 *          
 *          - Input array: [2, 3, 4, 8]
 *          - Initialize 'dp' with all 1s.
 *          - Iterating through the array:
 * 
 *              [2, 3, 4, 8]
 *               1  1  2  ^
 *              
 *              first:
 *              dp[8] = 1;             
 * 
 *              j=0:
 *              (8%2 == 0 && dp.find(8/2 == 4) != dp.end()) 
 *                  dp[8] += (dp[2] * dp[4]) == 1 * 2
 * 
 *              later j=2:
 *              (8%4 == 0 && dp.find(8/4 == 2) != dp.end()) 
 *                  dp[8] += (dp[4] * dp[2]) == 2 * 1
 *              
 *              then:
 *              dp[8] = 5;
 * 
 *          - Binary Trees:                     
 *              [2], [3], [4], [4,2,2] [8], [8,4,4], [8,4,4,2,2], [8,4,2,2,4], [8,4,2,2,4,2,2]
 *          
 *                 8     -> 1 binary tree
 *               4   4   -> 1 binary tree
 *              2 2 2 2  -> 3 binary tree (exculding one of the sides or adding both sides)
 * 
 *      Time: O(N^2)
 *      Space: O(N)
 */

class Solution {
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::unordered_map<int, long> dp;

        for(int i = 0; i < arr.size(); ++i)
        {
            int& num = arr[i];
            dp[num] = 1;

            for(int j = 0; j < i; ++j)
            {
                int& compare = arr[j];
                if(num % compare == 0 && dp.find(num / compare) != dp.end())
                {
                    dp[num] += dp[compare] * dp[num / compare];
                }
            }
        }

        long num_binary_trees = 0;
        for(const std::pair<int, long>& pair : dp)
        {
            num_binary_trees += pair.second;
        }

        return num_binary_trees % (int)(1e9 + 7);
    }
};