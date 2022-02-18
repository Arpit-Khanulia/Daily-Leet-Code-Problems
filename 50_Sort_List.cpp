// https://leetcode.com/problems/sort-list/
// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:

// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []


//    Definition for singly-linked list.
//    struct ListNode {
//        int val;
//        ListNode *next;
//        ListNode() : val(0), next(nullptr) {}
//        ListNode(int x) : val(x), next(nullptr) {}
//        ListNode(int x, ListNode *next) : val(x), next(next) {}
//    };


// ********** method 1 time O(nlogn) space O(n)****************


// class Solution
// {
// public:
//     ListNode *sortList(ListNode *head)
//     {
//         vector<int> sorted;
//         ListNode *temp = head;

//         if (head == NULL)
//             return NULL;

//         while (temp != NULL)
//         {
//             sorted.push_back(temp->val);
//             temp = temp->next;
//         }
//         temp = head;

//         sort(sorted.begin(), sorted.end());
//         int i = 0;

//         while (temp != NULL)
//         {
//             temp->val = sorted[i];
//             temp = temp->next;
//             i++;
//         }

//         return head;
//     }
// };
