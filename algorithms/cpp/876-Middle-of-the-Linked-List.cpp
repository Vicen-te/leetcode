// Author  :   Vicen-te
// Date    :   09/10/2022

/*
    Given the head of a singly linked list, return the middle node of the linked list.
    If there are two middle nodes, return the second middle node.

    Ex. 
    Input: head = [1,2,3,4,5]
    Output: [3,4,5]

    1.- Set two pointers (one takes the next node / one by one, 
        two takes the next node from the next node / two by two)
    2.- Check the position of two or the one next to two
    3.- Continue until the two position or the one next to two is null

    Time: O(N) 
    Space: O(1)
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
    ListNode* middleNode(ListNode* head) {
        ListNode* one = head;
        ListNode* two = head;

        while (two != NULL && two->next != NULL) {
            one = one->next;
            two = two->next->next;
        }
        return one;
    }
};