#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
   public:
      int lengthOfLongestSubstring(string s)
      {
         // Keep a map of char -> index found at
         std::unordered_map<char, short> chars;
         chars.reserve(s.size());
         short longestSubstrLength = 0;
         short beginIdx = 0;

         for (size_t i = 0; i < s.size(); i++)
         {
            char c = s[i];
            auto ci = chars.find(c);

            if (ci == chars.end())
            {
               chars.emplace(c, i);
            }
            else
            {
               if (ci->second + 1 > beginIdx)
               {
                  beginIdx = ci->second + 1;
               }

               ci->second = i;
            }

            short curSubstrLength = i + 1 - beginIdx;
            if (curSubstrLength > longestSubstrLength)
            {
               longestSubstrLength = curSubstrLength;
            }
         }
         return longestSubstrLength;
      }
};

int main()
{
   Solution s;

   std::cout << s.lengthOfLongestSubstring(std::string("aab")) << std::endl;
   std::cout << s.lengthOfLongestSubstring(std::string("bbbbb")) << std::endl;
   std::cout << s.lengthOfLongestSubstring(std::string("pwwkew")) << std::endl;
   std::cout << s.lengthOfLongestSubstring(std::string("dvdf")) << std::endl;
   std::cout << s.lengthOfLongestSubstring(std::string("anviaj")) << std::endl;
   std::cout << s.lengthOfLongestSubstring(std::string("bedvdfabcdxb")) << std::endl;
}
