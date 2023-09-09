// Author  :   Vicen-te
// Date    :   09/09/2023

/*
    Given an array of distinct integers nums and a target integer target, 
    return the number of possible combinations that add up to target.

    The test cases are generated so that the answer can fit in a 32-bit integer.

    Ex. 
    Input: nums = [1,2,3], target = 4
    Output: 7
    Explanation:
    The possible combination ways are:
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)
    Note that different sequences are counted as different combinations.

    1.- Set a vector to store targets from 0 to ours.
    2.- Set index value 0 to 1 (it does not need any number that is why it would only be executed once)
    3.- For each number up to the target, we check if for each num in nums if the subtraction of the
        current target(i) minus the actual num is greater than or equal to 0 (i - num >= 0). 
        This will give us the target (its combinations) that we will have to add to know the 
        combinations of the current target(i). 

        Explanation Ex. (This is one iteration of the code to understan whats going on)

            nums = [1,2,3], target = 4, custom target (i) = 3, actual num = 1
            idea: if we have added 1, we need to get the remaining +2 needing the target of 2
            
            target calculation =       i        -            num                = 3-1 = 2
                                (current target)  (actual number = added number)

            target(2) has two options that will have been added in past iterations:
                target(1) = target(0) if we choose number 1
                target(0) = 1         if we choose number 2.

            target to add to current target(i=3) += target(2 => i-num)

    Time: O(N*M)
    Space: O(M)
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i < target + 1; ++i)
        {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};