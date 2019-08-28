#include <stddef.h>

/**
 * Problem:
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example:
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 * Result:
 *
 * Runtime: 24 ms, faster than 65.45% of C++ online submissions for Add Two Numbers.
 * Memory Usage: 10.3 MB, less than 90.86% of C++ online submissions for Add Two Numbers.
 */

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
   {
      int carry = 0;
      ListNode* curL1 = l1;
      ListNode* curL2 = l2;
      ListNode* cur = nullptr;
      ListNode* ret = nullptr;

      while (curL1 != NULL || curL2 != NULL || carry != 0)
      {
         int val1 = 0;
         if (curL1 != NULL)
         {
            val1 = curL1->val;
            curL1 = curL1->next;
         }

         int val2 = 0;
         if (curL2 != NULL)
         {
            val2 = curL2->val;
            curL2 = curL2->next;
         }

         int newCarry = (val1 + val2 + carry) / 10;
         int result = (val1 + val2 + carry) % 10;

         carry = newCarry;

         if (cur == nullptr)
         {
            cur = new ListNode(result);
            ret = cur;
         }
         else
         {
            cur->next = new ListNode(result);
            cur = cur->next;
         }
      }
      return ret;
   }
};
