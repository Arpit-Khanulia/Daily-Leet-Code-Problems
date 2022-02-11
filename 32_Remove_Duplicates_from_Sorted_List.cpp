
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/



// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,1,2]
// Output: [1,2]
// Example 2:


// Input: head = [1,1,2,3,3]
// Output: [1,2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order



// Leetcode

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
        
//          if(head==NULL || head->next == NULL)
//              return head;
        
//         ListNode * start = head;
        
//         while(head->next != NULL)
//         {
//             if(head-> val == head->next->val)
//                 head->next = head->next->next;
//             else
//                 head = head->next;
//         }  
//         return start;   
//     }
// };