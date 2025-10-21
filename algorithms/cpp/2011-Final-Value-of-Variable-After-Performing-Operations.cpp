// Author  :   Vicen-te
// Date    :   10/21/2025 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      You are given an array of strings operations, each representing an operation on a variable X.
 *      The operations can be:
 *          "++X" or "X++" → increment X by 1
 *          "--X" or "X--" → decrement X by 1
 *      Initially, X = 0.
 *      Return the final value of X after performing all operations.
 * 
 *  Example 1:
 *      Input: operations = ["--X","X++","X++"]
 *      Process:
 *          Step 1: X = 0
 *          Step 2: "--X" → X = -1
 *          Step 3: "X++" → X = 0
 *          Step 4: "X++" → X = 1
 *      Output: 1
 * 
 *  Example 2:
 *      Input: operations = ["++X","++X","X++"]
 *      Output: 3
 * 
 *  Example 3:
 *      Input: operations = ["X++","++X","--X","X--"]
 *      Output: 0
 * 
 *  Constraints:
 *      1 <= operations.length <= 100
 *      operations[i] is "++X", "X++", "--X", or "X--"
 * 
 * 
 *  Algorithm:
 *      - Iterate through each operation string.
 *      - Check the second character (op[1]):
 *          '+' → increment accumulator by 1
 *          '-' → decrement accumulator by 1
 *      - Return the final accumulated value.
 * 
 *  Complexity:
 *      Time: O(N)   (traverse operations once)
 *      Space: O(1)  (only an integer accumulator)
 * 
 */

class Solution 
{
public:
    int finalValueAfterOperations(const std::vector<std::string>& operations) 
    {
        return std::accumulate
        (
            operations.begin(), 
            operations.end(), 
            0,
            [](int acc, const std::string& op) 
            { 
                return acc + (op[1] == '+' ? 1 : -1); 
            }
        );
    }
};
