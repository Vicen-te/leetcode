// Author  :   Vicen-te
// Date    :   09/29/2023 (MM-DD-YYYY)

/*
 *  Description:
 *      An array is monotonic if it is either monotone increasing or monotone decreasing.
 *      An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. 
 *      An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
 *
 *      Given an integer array nums, return true if the given array is monotonic, or false otherwise.
 *
 *      Ex1. 
 *          Input: nums = [1,2,2,3]
 *          Output: true
 *      Ex2.
 *          Input: nums = [6,5,4,4]
 *          Output: true
 *      Ex3.
 *          Input: nums = [1,3,2]
 *          Output: false
 * 
 *  Algorithm:
 *      1. For each number in 'nums', check if the current number is greater than or less than 
 *         the next one.
 *      2. If either of the last comparisons occurs, one option will be discarded;
 *         if both occur, it is not monotonic.
 *      3. Return whether it's decreasing or increasing.
 *
 *  Time Complexity: O(N) 
 *  Space Complexity: O(1)
*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        for (vector<int>::iterator it = nums.begin(), next = it + 1; it < --nums.end(); ++it, ++next)
        {
            if(*it < *next)
            {
                decreasing = false;
            }

            if(*it > *next)
            {
                increasing = false;
            }
        }

        return increasing || decreasing;
    }
};