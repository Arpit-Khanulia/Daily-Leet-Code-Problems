// https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// c++ code by method 1

// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {

//         if (head->next == NULL)
//             return NULL;

//                 ListNode *temp = head;
//         int count = 0;

//         while (temp != NULL)
//         {
//             temp = temp->next;
//             count++;
//         }

//         int no = count - n;
//         temp = head;

//         if (no == 0)
//             return head->next;

//         while (--no)
//             temp = temp->next;

//         temp->next = temp->next->next;

//         return head;
//     }
// };

// java code by method 2

// class Solution {
//     public ListNode removeNthFromEnd(ListNode head, int n) {

//         if(head.next == null)
//             return null;

//         ListNode blank = new ListNode();
//         blank.next = head;
//         ListNode  tortoise = blank;
//         ListNode hare = head;

//         while(n>1){
//             n--;
//             hare = hare.next;
//         }

//         while(hare.next!= null) {
//             hare = hare.next;
//             tortoise= tortoise.next;
//         }

//         tortoise.next = (tortoise.next).next;

//         return blank.next;

//     }
// }