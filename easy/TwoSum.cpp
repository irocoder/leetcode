#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
   // Attempt to solve in O(N) time.
   vector<int> twoSum(vector<int>& nums, int target)
   {
      vector<int> ret;
      unordered_map<int, int> um;
      unordered_map<int, int> dup;

      for (int i = 0; i < nums.size(); i++)
      {
         if (um.find(nums[i]) == um.end())
            um.emplace(nums[i], i);
         else
            dup.emplace(nums[i], i);
      }

      for (auto i = um.begin(); i != um.end(); i++)
      {
         int f = target - i->first;
         unordered_map<int, int>::const_iterator l = um.find(f);

         if (l != um.end() && l != i)
         {
            ret.push_back(i->second);
            ret.push_back(l->second);
            return ret;
         }

         l = dup.find(f);
         if (l != dup.end())
         {
            ret.push_back(i->second);
            ret.push_back(l->second);
            return ret;
         }
      }

      return ret;
   }
};

int main()
{
   vector<int> nums { 0, 4, 3, 0 };

   Solution s;
   vector<int> v = s.twoSum(nums, 0);
   cout << "[ ";
   for (auto i = v.begin(); i != v.end(); i++)
   {
      cout << *i << ", ";
   }
   cout << "]" << endl;
}
