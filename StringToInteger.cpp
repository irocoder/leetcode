#include <string>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
	public:
		int myAtoi(string str)
		{
			int n = 0;
			int startIdx = 0;

			while (str[startIdx] == ' ')
				startIdx++;

			bool isNegative = str[startIdx] == '-';
			if (str[startIdx] == '-' || str[startIdx] == '+')
				startIdx++;

			while (str[startIdx] == '0')
				startIdx++;

			if (!(str[startIdx] >= '0' && str[startIdx] <= '9'))
				return 0;

			for (int i = startIdx; i < str.size(); i++)
			{
				char c = str[i];
				if (!(c >= '0' && c <= '9'))
				{
					return isNegative ? -n : n;
				}

				int d = (int)(c - '0');
				if (INT_MAX / 10 < n)
					return isNegative ? INT_MIN : INT_MAX;

				n *= 10;

				if (n > INT_MAX - d)
					return isNegative ? INT_MIN : INT_MAX;

				n += d;
			}

			return isNegative ? -n : n;
		}
};


int main()
{
	Solution s;
	cout << s.myAtoi("42") << endl;
	cout << s.myAtoi("-4193 with words") << endl;
	cout << s.myAtoi("words and 987") << endl;
	cout << s.myAtoi("-91283472332") << endl;
	cout << s.myAtoi("  0000000000012345678") << endl;
	cout << s.myAtoi("-000000000000000000000000000000000000000000000000001") << endl;
	cout << s.myAtoi("2147483800") << endl;
	cout << s.myAtoi("+1") << endl;
	cout << s.myAtoi("-+1") << endl;
	cout << s.myAtoi("+-1") << endl;
	cout << s.myAtoi("--1") << endl;
	cout << s.myAtoi("00+1") << endl;


	return 0;
}
