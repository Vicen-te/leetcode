// Author  :   Vicen-te
// Date    :   10/25/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. 
 * 
 *      Now in every subsequent row, we look at the previous row and replace each occurrence 
 *      of 0 with 01, and each occurrence of 1 with 10.
 * 
 *          For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
 * 
 *      Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.
 * 
 *      Ex1.
 *          Input: n = 1, k = 1
 *          Output: 0
 *          Explanation: row 1: 0
 *                              ^
 * 
 *      Ex2.
 *          Input: n = 2, k = 1
 *          Output: 0
 *          Explanation: 
 *          row 1: 0
 *          row 2: 01
 *                 ^
 * 
 *      Ex3.
 *          Input: n = 2, k = 2
 *          Output: 1
 *          Explanation: 
 *          row 1: 0
 *          row 2: 01
 *                  ^
 * 
 *  Algorithm:
 *      - Each row is formed by flipping the previous row's values (e.g., 01 to 10), 
 *        generating a sequence (e.g., 0110 for the 3rd row).
 * 
 *      - If above the middle position in a row, return the inverted value (!0 is 1, and !1 is 0)
 *        and adjust 'n' for the next iteration.
 * 
 *      - Continue this process until reaching the first row (k equals 1), where the initial value
 *        is returned (0 for row 1).
 * 
 *      Time: O(N)
 *      Space: O(N)
 * 
 */

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1 && k == 1) return 0;
        int mid = pow(2, n-1) / 2;
        if(k > mid) return !kthGrammar(n-1,k-mid);
        else return kthGrammar(n-1, k);
    }
};