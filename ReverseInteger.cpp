#include <iostream>
#include <cmath>
#include <limits.h>

class Solution
{
   public:
      int reverse(int x)
      {
         int n = 0;
         int fac = 0;
         bool isNegative = x < 0;

         while ((int)(x / std::pow(10, fac + 1)) != 0)
         {
            fac++;
         }

         for (int i = 0; i <= fac; i++)
         {
            long j = (x % 10) * std::pow(10, fac - i);
            n += j;

            if ((n > 0 && isNegative) || (n < 0 && !isNegative) || (j < INT_MIN) || (j > INT_MAX))
            {
               return 0;
            }

            x = (int)(x / 10);
         }

         return n;
      }
};

// Test code
int main()
{
   int num = -33243;

   std::cout << s.reverse(num) << std::endl;
}
