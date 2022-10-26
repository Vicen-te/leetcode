// Author  :   Vicen-te
// Date    :   20/10/2022

/*
    Roman numerals are represented by seven different symbols: 
    I, V, X, L, C, D and M.

    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.

    Given an integer, convert it to a roman numeral.

    Ex. 
    Input: num = 58
    Output: "LVIII"

    1.- Create an Integer and a String with its matching letter and value
    2.- Traverse the entire array (13), until n == 0 (false).
        Note: n != 0 (true).
    3.- If the number entered is greater than the number being compared, 
        the letter is assigned and the value of the number entered 
        is subtracted.

    Time: O(N) 
    Space: O(N)
*/

class Solution {
public:
    const int val[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
    const string roman[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

    string intToRoman(int N) {
        string ans = "";
        for (int i = 0; N; i++)
            while (N >= val[i]) 
                ans += roman[i], N -= val[i];
        return ans;
    }
};