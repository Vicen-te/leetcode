// Author  :   Vicen-te
// Date    :   08/10/2022

/*
    Given a string s, reverse the order of characters in each word within
    a sentence while still preserving whitespace and initial word order.

    Ex. 
    Input: s = "Let's take LeetCode contest"
    Output: "s'teL ekat edoCteeL tsetnoc"

    1.- Search for a space or wait unitl the end of the sentence.
    2.- Swap the characters in the left and right side of the string, 
        unitl you get one points to the other.
    3.- Save the last space for the next iteration.

    Time: O(N) 
    Space: O(1)
*/

class Solution {
public:
    string reverseWords(string s) {
        int lastSpace = -1;

        for (int i = 0; i <= s.length(); i++) {
            if (s[i] == ' ' || i == s.length())
            {
                int left = lastSpace + 1;
                int right = i - 1;

                while (left < right)
                {
                    char temp = s[right];
                    s[right--] = s[left];
                    s[left++] = temp;
                }
                lastSpace = i;
            }
        }
        return s;
    }
};