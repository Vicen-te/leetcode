// Author  :   Vicen-te
// Date    :   09/28/2023 (MM-DD-YYYY)

/*
 *  Description:
 *      Given an integer array nums, move all the even integers at the beginning of the array 
 *      followed by all the odd integers.
 * 
 *      Return any array that satisfies this condition.
 *
 *      Ex1. 
 *          Input: nums = [3,1,2,4]
 *          Output: [2,4,3,1]
 *          Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 *      Ex2.
 *          Input: nums = [0]
 *          Output: [0]
 * 
 *  Algorithm:
 *      1. We have two pointers: one that points to our current position in the array, 'i'; 
 *         and another that points to the first position, 'begin'.
 *      
 *      2. If the number of the first pointer, which points to a position in the array, is even, 
 *         we will attempt to swap that number with the number located at the 'begin' position.
 *         And then we increase the 'begin' position."
 *      
 *      3. If begin != i , it means they are not in the same position, and therefore, it is necessary to swap the numbers.
 * 
 *      4. Thus, obtaining even numbers in the first part of the array and odd numbers in the last part.
 *      
 *
 *  Time Complexity: O(N) 
 *  Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        size_t begin = 0;

        for (size_t i = 0; i < nums.size(); ++i)
        {
            if(nums[i] % 2 == 0)
            {
                if(begin != i)
                {
                    nums[i] ^= nums[begin];
                    nums[begin] ^= nums[i];
                    nums[i] ^= nums[begin];
                }   
                ++begin;
            }
        }

        return nums;
    }
};