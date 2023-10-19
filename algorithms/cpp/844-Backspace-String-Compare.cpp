// Author  :   Vicen-te
// Date    :   10/19/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      Given two strings s and t, return true if they are equal when both are typed into empty
 *      text editors. '#' means a backspace character.
 * 
 *      Note that after backspacing an empty text, the text will continue empty.
 *  
 *      Ex1.
 *          Input: s = "ab#c", t = "ad#c"
 *          Output: true
 *          Explanation: Both s and t become "ac".
 * 
 *      Ex2.
 *          Input: s = "a#c", t = "b"
 *          Output: true
 *          Explanation: Both s and t become "".
 * 
 *      Ex3.
 *          Input: s = "ab#c", t = "ad#c"
 *          Output: false
 *          Explanation: s becomes "c" while t becomes "b".
 * 
 *  Algorithm:
 *      1. Search for the first occurrence of '#' in the string and position the iterator 'it'
 *         at that character.
 *      2. Continuously remove the '#' character and the preceding character (if applicable) 
 *         pointed to by 'it' until there are no more '#' characters in the string.
 *      3. After all backspaces have been removed, compare the modified strings 's' and 't'.
 *      4. If 's' and 't' are identical, return true; otherwise, return false.
 * 
 *      Time: O(N)
 *      Space: O(1)
 */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        removeLetters(s);
        removeLetters(t);
        return t == s;
    }

    void removeLetters(string& s)
    {
        string::iterator it = find(s.begin(), s.end(), '#');
        while(it != s.end())
        {
            if(it == s.begin())
            {
                s.erase(it);
                it = find(s.begin(), s.end(), '#');
                continue;
            }

            s.erase(it);
            s.erase(it-1);
            it = find(s.begin(), s.end(), '#');
        }
    }
};