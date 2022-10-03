// Author  :   Vicen-te
// Date    :   03/10/2022

/*
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Ex.
    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]

    1.- Create an integer (pos) to establish the position you are in without zeros.
    2.- Change every time you find a non-zero number, and add 1 to the pos.
    3.- All zeros will be at the end of the array.

    Time: O(N)
    Space: O(1)
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for (int i = 0, pos = 0; i < nums.size(); ++i)
            if (nums[i] != 0)
                swap(nums[pos++], nums[i]);
    }
};