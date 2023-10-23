// Author  :   Vicen-te
// Date    :   10/20/2023 (MM-DD-YYYY)

/**
 * 
 *  Description:
 *      You are given a nested list of integers nestedList. Each element is either an integer or a
 *      list whose elements may also be integers or other lists. Implement an iterator to flatten it.
 * 
 *      Implement the NestedIterator class:
 *  
 *          - NestedIterator(List<NestedInteger> nestedList) Initializes the iterator with the 
 *            nested list nestedList.
 *          - int next() Returns the next integer in the nested list.
 *          - boolean hasNext() Returns true if there are still some integers in the nested list
 *            and false otherwise.
 * 
 *      Your code will be tested with the following pseudocode:
 * 
 *          initialize iterator with nestedList
 *          res = []
 *          while iterator.hasNext()
 *              append iterator.next() to the end of res
 *          return res
 * 
 *      If res matches the expected flattened list, then your code will be judged as correct.
 * 
 *      Ex1.
 *          Input: nestedList = [[1,1],2,[1,1]]
 *          Output: [1,1,2,1,1]
 *          Explanation: By calling next repeatedly until hasNext returns false, the order of
 *          elements returned by next should be: [1,1,2,1,1].
 * 
 *      Ex2.
 *          Input: nestedList = [1,[4,[6]]]
 *          Output: [1,4,6]
 *          Explanation: By calling next repeatedly until hasNext returns false, the order of
 *          elements returned by next should be: [1,4,6].
 * 
 *  Algorithm:
 *      - This algorithm flattens nested lists of numbers into a flat sequence. 
 * 
 *      - It uses a queue for organization and employs a recursive method to process the nested 
 *        structure and place the numbers in the queue. 
 * 
 *      - The 'next' function retrieves the next number from the queue, and 'hasNext' checks if
 *        there are more numbers to retrieve.
 * 
 *      Time: O(N)
 *      Space: O(N)
 */

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int> queue;

    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    void flatten(vector<NestedInteger> &nestedList)
    {
        for(vector<NestedInteger>::iterator it = nestedList.begin(); it != nestedList.end(); ++it)
        {
            if(it->isInteger())
            {
                queue.push(it->getInteger());
            }
            else
            {
                flatten(it->getList());
            }
        }
    }
    
    int next() {
        int value = queue.front();
        queue.pop();
        return value;
    }
    
    bool hasNext() {
        return !queue.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */