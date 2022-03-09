// https://leetcode.com/problems/reorder-list/submissions/

// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [1,4,2,3]
// Example 2:


// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]


// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// class Solution
// {
// public:
//     void reorderList(ListNode *head)
//     {

//         if (head->next == NULL)
//             return;

//         ListNode *hare = head->next;
//         ListNode *tortoise = head;

//         while (hare != NULL && hare->next != NULL)
//         {
//             hare = hare->next->next;
//             tortoise = tortoise->next;
//         }

//         ListNode *superfast = tortoise->next;
//         ListNode *fast = tortoise->next;
//         tortoise->next = NULL;
//         ListNode *slow = NULL;

//         while (fast != NULL)
//         {
//             superfast = superfast->next;
//             fast->next = slow;
//             slow = fast;
//             fast = superfast;
//         }

//         ListNode *left = head->next;
//         ListNode *right = slow->next;

//         while (head != NULL && slow != NULL)
//         {
//             head->next = slow;
//             head = left;
//             slow->next = head;
//             slow = right;

//             if (left != NULL && right != NULL)
//             {
//                 left = left->next;
//                 right = right->next;
//             }
//         }
//     }
// };