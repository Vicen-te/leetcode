// Author  :   Vicen-te
// Date    :   09/10/2022

/*
    Given the head of a linked list, 
    remove the nth node from the end of the list and return its head.

    Ex. 
    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]

    1.- Store the head in two temporary variables

    2.- Change the start of the pointer first to start at n 
        position and check if the input it's null.

    3.- Then the first and second pointer keep going until the first reach the end.
        the second starts with n-step delay, 
        the second one by the end will be on the right position.

    4.- Then update linkage of second pointer and remove 
        the N-th node from the end.

    5.- Empty(delete the reference: nullptr) and delete the pointers. (MemoryLeaks)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode* second = head;

        for (int i = 0; i < n; i++)
            first = first->next;

        if (first == nullptr)
            return head->next;

        while (first->next != nullptr) {
            second = second->next;
            first = first->next;
        }

        second->next = second->next->next;

        first = nullptr;
        second = nullptr;
        delete(first);
        delete(second);

        return head;
    }
};