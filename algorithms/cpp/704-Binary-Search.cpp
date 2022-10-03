// Author  :   Vicen-te
// Date    :   01/10/2022

/*
    Given an array of integers nums which is sorted in ascending order
    and an integer target, write a function to search target in nums. 
    
    If target exists, then return its index. 
    Otherwise, return -1.

    Ex. 
    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4

    Since array is sorted, perform binary search

    Time: O(log n)
    Space: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = (end + start) / 2;

            if (target < nums[mid]) end = mid - 1;
            else if (target > nums[mid]) start = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};