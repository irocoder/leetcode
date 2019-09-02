#include <vector>
#include <string>
#include <iostream>

class Solution
{
public:
   std::string longestCommonPrefix(std::vector<std::string>& strs)
   {
      int i = 0;
      std::string prefix;

      if (strs.empty())
      {
         return prefix;
      }

      while (true)
      {
         char previousChar = strs[0][i];

         for (int k = 0; k < strs.size(); k++)
         {
            std::string& str = strs[k];
            if (i >= str.size() || str[i] != previousChar)
            {
               return prefix;
            }
         }

         prefix.push_back(previousChar);

         i++;
      }

      return prefix;
   }
};

int main()
{
   Solution s;
   std::vector<std::string> strs;
   strs.push_back("flower");
   strs.push_back("flow");
   strs.push_back("flight");

   std::cout << s.longestCommonPrefix(strs) << std::endl;

   return 0;
}
