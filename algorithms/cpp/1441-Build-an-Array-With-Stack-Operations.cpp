// Author  :   Vicen-te
// Date    :   11/03/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      You are given an integer array target and an integer n.
 * 
 *      You have an empty stack with the two following operations:
 *          - "Push": pushes an integer to the top of the stack.
 *          - "Pop": removes the integer on the top of the stack.
 * 
 *      You also have a stream of the integers in the range [1, n].
 *      
 *      Use the two stack operations to make the numbers in the stack (from the bottom to the top)
 *      equal to target. You should follow the following rules:
 *          - If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.
 *          - If the stack is not empty, pop the integer at the top of the stack.
 *          - If, at any moment, the elements in the stack (from the bottom to the top) are equal to target, do not read new integers from the stream and do not do more operations on the stack.
 * 
 *      Return the stack operations needed to build target following the mentioned rules. If there are multiple valid answers, return any of them.
 *  
 *      Ex1.
 *          Input: target = [1,3], n = 3
 *          Output: ["Push","Push","Pop","Push"]
 *          Explanation: 
 *              Initially the stack s is empty. The last element is the top of the stack.
 *              Read 1 from the stream and push it to the stack. s = [1].
 *              Read 2 from the stream and push it to the stack. s = [1,2].
 *              Pop the integer on the top of the stack. s = [1].
 *              Read 3 from the stream and push it to the stack. s = [1,3].
 * 
 *  Algorithm:
 *
 *      Time Complexity: O(N)
 *      Space Complexity: O(N)
 *
 */

class Solution {
public:
    const string push = "Push";
    const string pop = "Pop";

    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> output;
        int index = 0;

        for(int i = 1; i <= n; ++i)
        {
            if(index == target.size()) break;

            if(target[index] == i)
            {
                output.push_back(push);
                ++index;
            }
            else
            {
                output.push_back(push);
                output.push_back(pop);
            }
        }
        return output;
    }
};