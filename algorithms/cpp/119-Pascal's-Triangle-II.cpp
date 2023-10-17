// Author  :   Vicen-te
// Date    :   10/16/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
 *      In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 *  
 *      Constraints: 1 <= numRows <= 30
 *  
 *      Ex1.
 *          Input: rowIndex = 3
 *          Output: [1,3,3,1]
 * 
 *      Ex2.
 *          Input: rowIndex = 0
 *          Output: [1]
 * 
 *      Ex3.
 *          Input: rowIndex = 1
 *          Output: [1,1]
 * 
 *  Algorithm:
 *      1. Initialize a vector 'output' of size 'rowIndex + 1' with all elements set to 1.
 *      2. Begin from the second-to-last position of the vector and iterate up to the second 
 *         position (inclusive). The first and last positions always have a value of 1.
 *      3. Starting from the second position up to the current row, update the 'output' vector by
 *         adding the value of the current element to the value of the element one position to the
 *         left.
 *      4. After processing all rows, return the 'output' vector, which now contains the rowIndexth
 *         row of Pascal's triangle.
 *  
 *      Example of progression:
 *          rowIndex: 4
 *              1 1 1 1 1
 *              1 2 3 4 1
 *              1 3 6 4 1
 *              1 4 6 4 1     
 * 
 *      Time: O(N^2)
 *      Space: O(N)
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output(rowIndex+1, 1);

        for (char i = rowIndex; i > 0; --i)
        {
            for (char j = 1; j < i; ++j)
            {
                output[j] += output[j-1];
            }
        }

        return output;
    }
};