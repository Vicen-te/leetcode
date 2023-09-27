// Author  :   Vicen-te
// Date    :   09/27/2022 (MM-DD-YYYY)

/*
    Description:
        You are given two strings word1 and word2. 
        Merge the strings by adding letters in alternating order, starting with word1.
        If a string is longer than the other, append the additional letters onto the end of 
        the merged string.

        Return the merged string.
    
        Ex1:
            Input: word1 = "abc", word2 = "pqr"
            Output: "apbqcr"
            Explanation: The merged string will be merged as so:
            word1:  a   b   c
            word2:    p   q   r
            merged: a p b q c r

    Algorithm: 
        Append each character from both words (word1, word2) to a new string variable.
        While the loop iterates, ensure that each word (word1, word2) remains within its length;
        otherwise, an error will occur.

        Time Complexity: O(N)
        Space Complexity: O(N)
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        
        for(int i = 0; i < word1.length() || i < word2.length(); ++i)
        {
            if(i < word1.length())
            {
                result += word1[i];
            }
            if(i < word2.length())
            {
                result += word2[i];
            }
        }

        return result;
    }
};
