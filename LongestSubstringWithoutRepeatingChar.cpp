#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
       int longestSubstrLength = 0;
       int curSubstrLength = 0;
       std::map<char, bool> usedChars;

       for (int i = 0; i < s.size(); i++)
       {
          char c = s[i];
          if (usedChars.find(c) != usedChars.end())
          {
            curSubstrLength = 1;
            usedChars.clear();
            usedChars.emplace(c, 1);
          }
          else
          {
            curSubstrLength++;
            if (curSubstrLength > longestSubstrLength)
            {
              longestSubstrLength = curSubstrLength;
            }
            usedChars.emplace(c, 1);
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

}
