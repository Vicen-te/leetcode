// Author  :   Vicen-te
// Date    :   09/30/2023 (MM-DD-YYYY)

/*
    Description:
        There are n kids with candies. You are given an integer array candies, where each candies[i]
        represents the number of candies the ith kid has, and an integer extraCandies, denoting the
        number of extra candies that you have.

        Return a boolean array result of length n, where result[i] is true if, after giving the ith
        kid all the extraCandies, they will have the greatest number of candies among all the kids,
        or false otherwise.

        Note that multiple kids can have the greatest number of candies.
    
        Ex1:
            Input: candies = [2,3,5,1,3], extraCandies = 3
            Output: [true,true,true,false,true] 
            Explanation: If you give all extraCandies to:
            - Kid 1, they will have 2 + 3 = 5 candies, which is the greatest among the kids.
            - Kid 2, they will have 3 + 3 = 6 candies, which is the greatest among the kids.
            - Kid 3, they will have 5 + 3 = 8 candies, which is the greatest among the kids.
            - Kid 4, they will have 1 + 3 = 4 candies, which is not the greatest among the kids.
            - Kid 5, they will have 3 + 3 = 6 candies, which is the greatest among the kids.

    Algorithm: 
        1. Firstly, We iterate through the vector to find the kid who has the greatest number of candies
        2. Secondly, For each child, we verify if the sum of their candies and the extra candies is
           greater than or equal to the child with the most candies.

        Time Complexity: O(N)
        Space Complexity: O(N)
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        uint8_t greatest = 0;
        for(vector<int>::iterator it = candies.begin(); it != candies.end(); ++it)
        {
            if(*it > greatest) greatest = *it;
        }

        vector<bool> boolean_array;
        for(vector<int>::iterator it = candies.begin(); it != candies.end(); ++it)
        {
            boolean_array.push_back(*it + extraCandies >= greatest);
        }

        return boolean_array;
    }
};