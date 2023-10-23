// Author  :   Vicen-te
// Date    :   10/23/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      Given an integer n, return true if it is a power of four. Otherwise, return false.
 * 
 *      An integer n is a power of four, if there exists an integer x such that n == 4x.
 * 
 *      Ex1.
 *          Input: n = 16
 *          Output: true
 * 
 *      Ex2.
 *          Input: n = 5
 *          Output: false
 * 
 *      Ex3.
 *          Input: n = 1
 *          Output: true
 * 
 *  Algorithm:
 *  To determine if an integer n is a power of four, we can use the following approach:
 *      
 *      1. Check if n is less than or equal to 0. 
 *         If it is, return false because negative numbers and zero cannot be powers of four.
 * 
 *      2. Check if n is a power of two by verifying that (n & (n - 1)) is zero. 
 *         If this condition is not met, return true, as powers of four must also be powers of two.
 * 
 *              (n & (n - 1)) = 0     -> false -> !(n & (n - 1)) = true  -> Power of two
 *              (n & (n - 1)) = x > 0 -> true  -> !(n & (n - 1)) = false
 * 
 *      3. Check if (n % 3 == 1). If this condition is satisfied, return true; powers of four have 
 *         a remainder of 1 when divided by 3.
 * 
 *      Time: O(1)
 *      Space: O(1)
 * 
 */

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        return !(n & n-1) && n % 3 == 1;
    }
};