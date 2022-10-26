// Author  :   Vicen-te
// Date    :   17/10/2022

/*
    Given an array of integers nums and an integer target, 
    return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution,
    and you may not use the same element twice.

    You can return the answer in any order.

    Ex. 
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]

    1.- Insert into a new vector of two values ​​the number and position of nums.
    2.- Sort the vector by number (in order).
    3.- Initialize the first and last position of the vector.
    4.- Check if the number is greater or less than the target.
        And it returns the position when the sum of the numbers matches the target.

    Time: O(NlogN)
    Space: O(N)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++)
            v.push_back({ nums[i],i });

        sort(v.begin(), v.end());

        int i = 0;
        int j = v.size() - 1;

        while (i < j)
        {
            if (v[i].first + v[j].first == target)
                return { v[i].second, v[j].second };

            if (v[i].first + v[j].first < target)
                i++;

            if (v[i].first + v[j].first > target)
                j--;
        }

        return { 0,0 };
    }
};