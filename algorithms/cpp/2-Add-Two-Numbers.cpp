// Author  :   Vicen-te
// Date    :   01/11/2022

/*
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order, 
    and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    You can return the answer in any order.

    Ex. 
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

    1.- Create an empty ListNode pointer, another with its reference.
    2.- Loop mean while pointers are not null or the sum is greater than 0. 
    3.- Check if the pointers are not null, then add the value of the ListNode
        to the sum variable and go to the next ListNode from the input pointers.
    4.- Create a ListNode with its correspondat vale.
    5.- Check if there is any number to carry and go to the next ListNode.

    Time: O(max(m,n))
    Space: O(max(m,n))
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* result = nullptr;
        ListNode** current = &result;

        while (l1 != nullptr || l2 != nullptr || sum > 0)
        {
            if (l1 != nullptr)
                sum += l1->val, l1 = l1->next;

            if (l2 != nullptr)
                sum += l2->val, l2 = l2->next;

            *current = new ListNode(sum % 10);
            sum /= 10;
            current = &((*current)->next);
        }
        return result;
    }
};