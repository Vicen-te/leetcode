// Author  :   Vicen-te
// Date    :   10/30/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      You are given an integer array arr. Sort the integers in the array in ascending order by
 *      the number of 1's in their binary representation and in case of two or more integers have
 *      the same number of 1's you have to sort them in ascending order.
 * 
 *      Return the array after sorting it.
 *  
 *      Ex1.
 *          Input: arr = [0,1,2,3,4,5,6,7,8]
 *          Output: [0,1,2,4,8,3,5,6,7]
 *          Explanation: 
 *              [0] is the only integer with 0 bits.
 *              [1,2,4,8] all have 1 bit.
 *              [3,5,6] have 2 bits.
 *              [7] has 3 bits.
 *              The sorted array by bits is [0,1,2,4,8,3,5,6,7]
 * 
 *      Ex2.
 *          Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
 *          Output: [1,2,4,8,16,32,64,128,256,512,1024]
 *          Explanation: 
 *              All integers have 1 bit in the binary representation, 
 *              you should just sort them in ascending order.
 * 
 *  Algorithm:
 *      This C++ solution uses the std::sort method to sort an array of integers based 
 *      on the count of set bits (1s) in their binary representations.
 * 
 *      The process involves the following steps:
 * 
 *          1. Initialize two variables, 'ca' and 'cb', to count the number of set bits 
 *             in integers 'a' and 'b.'
 * 
 *          2. Use bitwise operators to calculate the set bit count.
 * 
 *          3. If the set bit counts are equal, compare numerically; otherwise, sort by the
 *             set bit count in ascending order.
 *  
 *      Time: O(NlognN)
 *      Space: O(N)
 */

// Built-in Functions
class Solution {
public:
    static bool compare (int& a, int& b)
    {
        int ca = 0, cb = 0; //< Another option: __builtin_popcount

        for(int i = 0; i < 14; ++i){ // limit == 14 bits == 10^4
            if(a&(1<<i)){
                ++ca; 
            } 
        }
        for(int j = 0; j < 14; ++j){ 
            if(b&(1<<j)){ 
                ++cb; 
            } 
        }

        return (cb == ca) ? a < b : ca < cb;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);   
        return arr;
    }
};

// Brian Kerninghan's Algorithm
class Solution {
public:
    static int bits(int num) {
        int cnt = 0;
        while (num){
            num &= (num - 1);
            ++cnt;
        }
        return cnt;
    }
    
    static bool compare(int& a, int& b) {
        int ca = bits(a);
        int cb = bits(b);
        return (cb == ca) ? a < b : ca < cb;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};