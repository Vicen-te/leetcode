// Author  :   Vicen-te
// Date    :   13/10/2022

/*
    Given a string s, find the length of the longest substring 
    without repeating characters.

    Ex. 
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.

    1.- Set a range to store ASCII letters and add a
        sentiel value (termination condition): -1 which is equivalent to "null/none"
    2.- Set other integers to operate later: left, right, and string result.
    3.- Loop until you reach the end, check if there is another repeated character 
        or check if the maximum has changed.

    Time: O(N) 
    Space: O(N)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Senitel value: -1 -> 'null'/'none'
        vector<int> chars(128, -1);
        int left = 0;
        int right = 0;
        int res = 0;

        while (right < s.length())
        {
            char r = s[right];
            int index = chars[r];

            if (index != -1 and index >= left and index < right)
                left = index + 1;

            res = max(res, right - left + 1);
            chars[r] = right++; //add right to chars[r], then add 1 to right
        }
        return res;
    }
};