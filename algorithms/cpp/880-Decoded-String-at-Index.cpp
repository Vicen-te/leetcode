// Author  :   Vicen-te
// Date    :   09/28/2023 (MM-DD-YYYY)

/*
 *  Description:
 *      You are given an encoded string s. To decode the string to a tape, 
 *      the encoded string is read one character at a time and the following steps are taken:
 *
 *      If the character read is a letter, that letter is written onto the tape.
 *      If the character read is a digit d, the entire current tape is repeatedly written d - 1
 *      more times in total.
 * 
 *      Given an integer k, return the kth letter (1-indexed) in the decoded string.
 *
 *      Ex. 
 *          Input: s = "leet2code3", k = 10
 *          Output: "o"
 *          Explanation: The decoded string is "leetleetcodeleetleetcodeleetleetcode".
 *          The 10th letter in the string is "o".
 * 
 *  Algorithm:
 *      1. Calculate the length by adding the characters of the string and multiplying them by 
 *         the digit characters.
 *      2. Iterate through the string in reverse and check if the current character is a digit. 
 *      3. If it is, remove repeated words by dividing the length with the digit and adjust 
 *         the character's position(k) using the modulus operator(giving us the remainder). 
 *      4. If it's not a digit, check if the character's position(k) is equal to the length or 0 
 *         (this will indicate if it has reached the desired position) and return the desierd character
 *         if its true. If not, subtract one from the length.
 *
 *  Time Complexity: O(N) 
 *  Space Complexity: O(1)
*/

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long length = 0;
        uint8_t i = 0;

        while(i < s.length())
        {
            if(isdigit(s[i]))
            {
                length *= (s[i] - '0');
            }
            else
            {
                ++length;
            }
            ++i;
        }

        for (uint8_t j = i - 1; j >= 0; --j)
        {
            if (isdigit(s[j]))
            {
                length /= (s[j] - '0');
                k %= length;
            }
            else
            {
                if(k == length || k == 0)
                    return string(1, s[j]);
                --length;
            }
        }

        return "";
    }
};