/// Author  :   Vicen-te
/// Date    :   10/09/2023 (MM-DD-YYYY)

/**
 *  Description:
 *      Given an array of integers nums sorted in non-decreasing order, 
 *      find the starting and ending position of a given target value.
 * 
 *      If target is not found in the array, return [-1, -1].
 * 
 *      You must write an algorithm with O(log n) runtime complexity.
 *
 *      Ex1. 
 *          Input: nums = [5,7,7,8,8,10], target = 8
 *          Output: [3,4]
 *      Ex2.
 *          Input: nums = [5,7,7,8,8,10], target = 6
 *          Output: [-1,-1]
 *      Ex3.
 *          Input: nums = [], target = 0
 *          Output: [-1,-1]
 * 
 *  Algorithm:
 *      1. Utilize binary search to efficiently find the target element.
 *      2. Determine whether to search for the first or last occurrence and adjust the search range accordingly.
 *
 *  Time Complexity: O(log n) 
 *  Space Complexity: O(1)
 */

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool first)
    {
        int begin = 0;
        int end = nums.size()-1;
        int selected = -1;

        while(begin <= end)
        {
            int mid = begin + (end - begin) / 2;
            if(nums[mid] == target)
            {
                selected = mid;
                first ? end = --mid : begin = ++mid;
            }
            else if(nums[mid] < target)
            {
                begin = ++mid;
            }
            else
            {
                end = --mid;
            }
        }

        return selected;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
};