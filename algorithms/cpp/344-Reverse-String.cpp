// Author  :   Vicen-te
// Date    :   02/10/2022

/*
    Write a function that reverses a string. 
    The input string is given as an array of characters s.
    You must do this by modifying the input array in-place with O(1) extra memory.

    Ex. 
    Input: s = ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]

    1.- Set two pointers (1: position 0, 2: final position).
    2.- Swap the characters in the left and right side of the string, 
        unitl you get one pointing to the other.

    Time: O(N) 
    Space: O(1)
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (right > left)
            swap(s[left++], s[right--]);
    }
};