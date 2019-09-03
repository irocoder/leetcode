#include <string>
#include <unordered_map>
#include <stack>
#include <iostream>

using namespace std;

// Time complexity: O(n)
// Space complexity: O(n)
class Solution
{
   public:
      bool isValid(string s)
      {
         unordered_map<char, char> closers = {
            { ')', '(' },
            { ']', '[' },
            { '}', '{' }
         };
         stack<char> st;

         for (int i = 0; i < s.size(); i++)
         {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{')
            {
               st.push(c);
            }
            else
            {
               if (st.empty())
               {
                  return false;
               }

               if (closers[c] == st.top())
               {
                  st.pop();
               }
               else
               {
                  return false;
               }
            }
         }

         return st.empty();
      }
};

int main()
{
   Solution s;

   cout << s.isValid("()") << endl;
   cout << s.isValid("()[]{}") << endl;
   cout << s.isValid("(]") << endl;
   cout << s.isValid("([)]") << endl;
   cout << s.isValid("{([])}") << endl;
}
