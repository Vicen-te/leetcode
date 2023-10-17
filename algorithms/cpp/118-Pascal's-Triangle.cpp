// Author  :   Vicen-te
// Date    :   09/08/2023 (MM-DD-YYYY)

/**
    Given an integer numRows, return the first numRows of Pascal's triangle.
    In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

    Constraints: 1 <= numRows <= 30

    Ex.
    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

    1.- Create a 2D vector and push_back a vector of size 1 with the number 1.
    2.- For each row push_back a vector with row size + 1, with all numbers set to 1.
    3.- For each number except the first and last in each row, calculate the result of Pascal's Triangle.

    Time: O(N^2)
    Space: O(N^2)
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1}); 

        for (int i = 1; i < numRows; ++i) {
            result.push_back(vector<int>(i + 1, 1));
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
            }
        }

        return result;
    }
};