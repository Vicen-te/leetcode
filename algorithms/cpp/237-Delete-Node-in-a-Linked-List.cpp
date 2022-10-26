// Author  :   Vicen-te
// Date    :   13/10/2022

/*
    There is a singly-linked list head and we want to delete a node node in it.
    
    You are given the node to be deleted node. 
    You will not be given access to the first node of head.

    All the values of the linked list are unique, and it is guaranteed 
    that the given node node is not the last node in the linked list.

    Delete the given node. Note that by deleting the node, 
    we do not mean removing it from memory. We mean:

        The value of the given node should not exist in the linked list.
        The number of nodes in the linked list should decrease by one.
        All the values before node should be in the same order.
        All the values after node should be in the same order.

    Ex. 
    Input: head = [4,5,1,9], node = 5
    Output: [4,1,9]

    1.- Store the next node in a temporary variable.
    2.- Copy data of the next node to the current node.
    3.- Change the next pointer of the current node to the next pointer of the next node.
    4.- Empty the next pointer and delete the next node. (MemoryLeaks)

    Time: O(1) 
    Space: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;

        nextNode->next = nullptr;
        delete(nextNode);
    }
};