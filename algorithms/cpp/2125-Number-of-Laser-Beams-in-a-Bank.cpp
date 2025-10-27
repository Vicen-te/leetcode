// Author  :   Vicen-te
// Date    :   10/27/2025 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      You are given a 0-indexed binary string array `bank` representing the floor plan of a bank.
 *      Each row of `bank` consists of '0's (empty) and '1's (security devices). 
 *      
 *      A laser beam exists between two devices if:
 *          1. The devices are in different rows (r1 < r2).
 *          2. All rows between r1 and r2 have no devices.
 * 
 *      Return the total number of laser beams in the bank.
 * 
 *  Example 1:
 *      Input: bank = ["011001","000000","010100","001000"]
 *      Output: 8
 *      Explanation: 
 *          Beams exist between devices as follows:
 *              bank[0][1] -- bank[2][1]
 *              bank[0][1] -- bank[2][3]
 *              bank[0][2] -- bank[2][1]
 *              bank[0][2] -- bank[2][3]
 *              bank[0][5] -- bank[2][1]
 *              bank[0][5] -- bank[2][3]
 *              bank[2][1] -- bank[3][2]
 *              bank[2][3] -- bank[3][2]
 * 
 *  Example 2:
 *      Input: bank = ["000","111","000"]
 *      Output: 0
 * 
 *  Algorithm:
 *      - Iterate through each row of the bank.
 *      - Count the number of devices (ones) in the current row.
 *      - If the row has at least one device, multiply the count with the number of devices in
 *        the previous non-empty row and add to total beams.
 *      - Update the previous row device count for the next iteration.
 * 
 *  Complexity:
 *      Time: O(m * n), where m is the number of rows and n the number of columns.
 *      Space: O(1), constant extra space.
 */

class Solution {
public:
    int numberOfBeams(std::vector<std::string>& bank) 
    {
        int total = 0;   //< total beams
        int last = 0;    //< devices count in last non-empty row

        for (const auto& row : bank) 
        {
            int ones = 0;
            for (char c : row) ones += (c == '1'); //< count devices
            
            if (ones > 0) 
            {
                total += last * ones; //< beams between last row and current
                last = ones;          //< update last row device count
            }
        }

        return total;
    }
};
