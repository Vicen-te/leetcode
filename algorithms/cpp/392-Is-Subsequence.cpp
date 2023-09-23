// Author  :   Vicen-te
// Date    :   09/23/2023 (MM-DD-YYYY)

/*
    Problem Description:
        Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

        A subsequence of a string is a new string that is formed from the original string by 
        deleting some (can be none) of the characters without disturbing the relative positions 
        of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

        Ex1:
            Input: s = "abc", t = "ahbgdc"
            Output: true
        Ex2:
            Input: s = "axc", t = "ahbgdc"
            Output: false

    Algorithm:
        1. Create two variables to track the positions of the strings: 
           one for the subsequence (string s): j
           and one for the string where the subsequence may be (string t): i.

        2. Compare the characters of both strings at their respective positions. 
           If they are the same, increment the value of the variable j (position of the subsequence).

        3. If the position of the subsequence is equal to the length of the subsequence, 
           then the subsequence is inside the string where it may be (string t).

        Time Complexity: O(N) - size of the target string 
        Space Complexity: O(1)
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        
        while (j < s.length() && i < t.length())
        {
            if (t[i] == s[j]) ++j;
            ++i;
        }

        return j == s.length();
    }
};