/// Author  :   Vicen-te
/// Date    :   10/05/2023 (MM-DD-YYYY)

/**
 *  Description:
 *      Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 *
 *      Ex1. 
 *          Input: nums = [3,2,3]
 *          Output: [3]
 *      Ex2.
 *          Input: nums = [1]
 *          Output: [1]
 *      Ex3.
 *          Input: nums = [1,2]
 *          Output: [1,2]
 * 
 *      Follow-up: Could you solve the problem in linear time and in O(1) space?
 * 
 *  Algorithm:
 *      To find candidates in the given integer vector 'nums' that appear more than ⌊n/3⌋ times,
 *      we use the Boyer-Moore Majority Voting Algorithm.
 * 
 *      We initialize two variables: 'count1' and 'count2' to keep track of the counts of the two
 *      potential majority candidates, and 'candidate1' and 'candidate2' to store these candidates.
 * 
 *      We iterate through the vector, and for each element, we perform the following actions:
 *      - If 'count1' is zero, we set 'candidate1' to the current element.
 *      - If 'count2' is zero, we set 'candidate2' to the current element.
 *      - If the current element is equal to 'candidate1,' we increment 'count1.'
 *      - If the current element is equal to 'candidate2,' we increment 'count2.'
 *      - If the current element differs from both 'candidate1' and 'candidate2,' 
 *        we decrement 'count1' and 'count2.'
 * 
 *      After the first pass, we have two potential majority candidates, and we need to verify 
 *      their actual counts.
 * 
 *      We perform a second pass through the vector to count the occurrences of 'candidate1' and 
 *      'candidate2.'
 * 
 *      Finally, we check if the counts of 'candidate1' and 'candidate2' are greater than ⌊n/3⌋, 
 *      and if so, we add them to the result vector.
 *
 *  Time Complexity: O(N) 
 *  Space Complexity: O(1)
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN;
        int candidate2 = INT_MIN;
        int count1 = 0;
        int count2 = 0;
        const int size = nums.size();

        for (int& num : nums)
        {
            if(count1 == 0 && candidate2 != num)
            {
                candidate1 = num;
            }
            else if(count2 == 0 && candidate1 != num)
            {
                candidate2 = num;
            }    
            
            if(candidate1 == num)
            {
                ++count1;
            }
            else if(candidate2 == num)
            {
                ++count2;
            }
            else
            {
                --count1;
                --count2;
            }
        }
        count1 = 0;
        count2 = 0;

        for (int& num : nums)
        {
            if(num == candidate1) ++count1;
            if(num == candidate2) ++count2;            
        }

        vector<int> result;
        const int threashold = floor(size/3);
        if(count1 > threashold) result.push_back(candidate1); 
        if(count2 > threashold) result.push_back(candidate2); 
        return result;
    }
};