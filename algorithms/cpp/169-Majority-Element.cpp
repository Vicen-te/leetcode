/// Author  :   Vicen-te
/// Date    :   10/05/2023 (MM-DD-YYYY)

/**
 *  Description:
 *      Given an array nums of size n, return the majority element.
 * 
 *      The majority element is the element that appears more than ⌊n / 2⌋ times. 
 *      You may assume that the majority element always exists in the array.
 *
 *      Ex1. 
 *          Input: nums = [3,2,3]
 *          Output: 3
 *      Ex2.
 *          Input: nums = [3,2,3]
 *          Output: 2
 * 
 *      Follow-up: Could you solve the problem in linear time and in O(1) space?
 * 
 *  Algorithm:
 *      We will use the Boyer-Moore Voting Algorithm to efficiently find the majority element in a 
 *      given vector.
 * 
 *      The algorithm initializes two variables: 'count' to keep track of the current element's 
 *      count and 'candidate' to store the majority candidate.
 * 
 *      It iterates through the vector, and for each element, it performs the following actions:
 *      - If 'count' is zero, it sets 'candidate' to the current element (designating it as the new
 *        majority candidate).
 *      - If the current element matches 'candidate,' it increments 'count.'
 *      - If the current element differs from 'candidate,' it decrements 'count.'
 * 
 *      By the end of the loop, 'candidate' contains the majority element.
 *
 *  Time Complexity: O(N) 
 *  Space Complexity: O(1)
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = INT_MIN;

        for (int& num : nums)
        {
            if (count == 0){
                candidate  = num;
            }

            if(num == candidate ){
                ++count;
            }
            else{
                --count;
            }
        }

        return candidate;
    }
};