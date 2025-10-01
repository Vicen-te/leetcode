// Author  :   Vicen-te
// Date    :   10/01/2025 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      You are given a 0-indexed integer array nums, where nums[i] is a digit between 0 and 9.
 *      The triangular sum of nums is the value of the only element present in nums after the following process:
 * 
 *      Process:
 *          1. If the array length n == 1, stop.
 *          2. Otherwise, build a new array newNums of length n - 1.
 *          3. For each index i (0 <= i < n - 1), set:
 *                 newNums[i] = (nums[i] + nums[i+1]) % 10
 *          4. Replace nums with newNums and repeat.
 * 
 *      The result is the final remaining element.
 * 
 *  Example 1:
 *      Input: nums = [2,5,3,4]
 *      Process:
 *          Step 1: [2,5,3,4] → [(2+5)%10=7, (5+3)%10=8, (3+4)%10=7] = [7,8,7]
 *          Step 2: [7,8,7]   → [(7+8)%10=5, (8+7)%10=5] = [5,5]
 *          Step 3: [5,5]     → [(5+5)%10=0] = [0]
 *      Output: 0
 * 
 *  Example 2:
 *      Input: nums = [1,2,3,4,5]
 *      Output: 8
 * 
 *  Algorithm:
 *      - Apply iterative reduction by summing adjacent elements modulo 10.
 *      - Continue until only one element remains.
 * 
 *  Complexity:
 *      Time: O(N^2)   (because each reduction shortens array by 1)
 *      Space: O(1)    (in-place reduction, ignoring recursion stack)
 * 
 *  Constraints:
 *      1 <= nums.length <= 1000
 *      0 <= nums[i] <= 9
 */


class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int size = nums.size();
        if (size == 1) return nums.back();  // base case
        
        for (int i = 1; i < size; ++i) {
            nums[i-1] = (nums[i-1] + nums[i]) % 10; // reduce in-place
        }
        
        nums.pop_back(); // shrink array size
        return triangularSum(nums); // recurse
    }
};
