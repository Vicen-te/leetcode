/// Author  :   Vicen-te
/// Date    :   10/15/2023 (MM-DD-YYYY)

/**
 *  Description:
 *      For two strings s and t, we say "t divides s" if and only if s = t + ... + t 
 *      (i.e., t is concatenated with itself one or more times).
 *
 *      Given two strings str1 and str2, return the largest string x such that x divides both 
 *      str1 and str2.
 * 
 *      Ex1:
 *          Input: str1 = "ABCABC", str2 = "ABC"
 *          Output: "ABC"
 *  
 *      Ex2:
 *          Input: str1 = "ABABAB", str2 = "ABAB"
 *          Output: "AB"
 *  
 *      Ex3:
 *          Input: str1 = "LEET", str2 = "CODE"
 *          Output: ""
 * 
 *  Algorithm:
 *      1. Determine the shortest and longest strings from the input.
 *      2. Iterate from the length of the shortest string down to 1.
 *      3. Check if both strings are divisible by the current length.
 *      4. Creates a 'first_pointer' variable ranging from 0 to the current length.
 *      5. Another variable 'second_pointer' checks if characters outside 'first_pointer' match.
 *      6. Accumulate matching characters from the longest string once, resetting the 'solution' if there's no match.
 *      7. If 'solution' is not empty, return it as the greatest common divisor; otherwise, return an empty string.
 * 
 *      Example of an iteration:
 *          
 *          i: 2 -> actual divisor
 *          j: 2 -> position in longest string
 * 
 *          ABABAB
 *            
 *            second_pointer: 2
 *            v
 *          ABAB
 *          ^
 *          first_pointer: 0
 *          
 *          range of first_pointer: (0,1)
 *            v 
 *          AB|AB
 * 
 *      Time Complexity: O(n^2) 
 *      Space Complexity: O(1)
 */

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string shortest, longest;
        
        if(str1.length() < str2.length()){
            shortest = str1;
            longest = str2;
        }
        else{
            shortest = str2;
            longest = str1;
        }

        string solution = "";   
        ushort shortest_length = shortest.length();
        ushort longest_length = longest.length();

        for(ushort i = shortest_length; i > 0; --i)
        {   
            if (longest_length % i != 0 || shortest_length % i != 0) continue;

            for(ushort j = 0; j < longest_length; ++j)
            {
                ushort first_pointer = j % i;
                ushort second_pointer = j % shortest_length;

                if(shortest[first_pointer] != longest[j] || shortest[second_pointer] != longest[j])
                {
                    solution = "";
                    break;
                }

                if(first_pointer == j) solution += longest[j];
            }
            
            if(solution != "") return solution;
        }

        return "";
    }
};