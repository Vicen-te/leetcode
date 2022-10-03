// Author  :   Vicen-te
// Date    :   03/10/2022

/*
    Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
    find two numbers such that they add up to a specific target number. 
    Let these two numbers be numbers[index1] and numbers[index2] where 
    1 <= index1 < index2 <= numbers.length.

    Return the indices of the two numbers, index1 and index2, 
    added by one as an integer array [index1, index2] of length 2.

    Ex. 
    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]

    1.- Set two pointers (1: position 0, 2: final position).
    2.- Sum the pointers and chek if its equal to the target.
    3.- If the second pointer is greater than the sum, subtract 1. 
    You can add 1 if the first pointer is less than the sum.
    4.- It will continue until you get the desired numbers or the pointers end up meeting

    Time: O(n)
    Space: O(1) 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i != j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
                return { ++i, ++j };
            else if (sum > target)
                --j;
            else
                ++i;
        }
        return { -1, -1 };
    }
};