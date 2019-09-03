#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time complexity: O(n)
// Space complexity: O(n)

struct ListNode {
   int val;
   ListNode* next;
   ListNode(int x) : val(x), next(NULL) {}
}

class Solution
{
   public:
      ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
      {
         ListNode* cur = NULL;

         if (l1 == NULL && l2 == NULL)
         {
            return NULL;
         }

         if (l2 == NULL || (l1 != NULL && l1->val < l2->val))
         {
            cur = l1;
            l1 = l1->next;
         }
         else if (l2 != NULL)
         {
            cur = l2;
            l2 = l2->next;
         }

         ListNode* ret = cur;

         while (l1 != NULL || l2 != NULL)
         {
            if (l2 == NULL || (l1 != NULL && l1->val < l2->val))
            {
               cur->next = l1;
               l1 = l1->next;
            }
            else if (l2 != NULL)
            {
               cur->next = l2;
               l2 = l2->next;
            }

            cur = cur->next;
         }

         return ret;
      }
};

int main()
{
   return 0;
}
