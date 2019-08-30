#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
   public:
      std::unordered_map<char, char> sub;
      std::unordered_map<char, short> val;

      Solution()
      {
         sub.emplace('V', 'I');
         sub.emplace('X', 'I');

         sub.emplace('L', 'X');
         sub.emplace('C', 'X');

         sub.emplace('D', 'C');
         sub.emplace('M', 'C');

         val.emplace('I', 1);
         val.emplace('V', 5);
         val.emplace('X', 10);
         val.emplace('L', 50);
         val.emplace('C', 100);
         val.emplace('D', 500);
         val.emplace('M', 1000);
      }

      int romanToInt(std::string s)
      {
         int sum = 0;
         int idx = 0;

         while (idx < s.size())
         {
            char cur = s[idx];
            short curVal = val[cur];

            if (idx + 1 >= s.size())
            {
               sum += curVal;
               break;
            }

            char next = s[idx + 1];
            short nextVal = val[next];

            if (sub[next] == cur)
            {
               sum += nextVal - curVal;
               idx += 2;
            }
            else
            {
               sum += curVal;
               idx += 1;
            }
         }

         return sum;
      }
};

int main()
{
   Solution s;

   std::cout << s.romanToInt("MCMXCIV") << std::endl;
   std::cout << s.romanToInt("LVIII") << std::endl;
   std::cout << s.romanToInt("IX") << std::endl;
   std::cout << s.romanToInt("IV") << std::endl;
   std::cout << s.romanToInt("III") << std::endl;

   return 0;
}
